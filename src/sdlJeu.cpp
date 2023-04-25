#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <X11/Xlib.h>

#define HAUTEUR 55
#define LARGEUR 200



#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}


// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);

    
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}


// ============= CLASS SDLJEU =============== //

SDLSimple::SDLSimple ()  : jeu_sdl() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;
    

    /*
	int dimx, dimy;
	dimx = jeu.getConstTerrain().getDimX();
	dimy = jeu.getConstTerrain().getDimY();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;
    */

    //Display *display = XOpenDisplay(nullptr);
    //Screen *screen = DefaultScreenOfDisplay(display);
    
    //const int screenWidth = screen->width;
    //const int screenHeight = screen->height;

	//jeu_sdl.960 = screenWidth;
    //jeu_sdl.640 = screenHeight;

    //XCloseDisplay(display);

	cout<<" SDL COUT : "<< 960<< " " << 640 <<endl;
    // Creation de la fenetre
    window = SDL_CreateWindow("FarmDefender", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_zombi.loadFromFile("data/Zombi.png",renderer);
    im_plaine.loadFromFile("data/carte2.png",renderer);
    im_batdef.loadFromFile("data/batdef.png",renderer);
    /*
    im_pacman.loadFromFile("data/pacman.png",renderer);
    im_mur.loadFromFile("data/mur.png",renderer);
    im_pastille.loadFromFile("data/pastille.png",renderer);
    im_fantome.loadFromFile("data/fantome.png",renderer);
    */

    // FONTS
    
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}
    
    
    
	font_color.r = 50;font_color.g = 50;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"TEST",font_color));
	font_im.loadFromCurrentSurface(renderer);
    

    // SONS
    
    if (withSound)
    {
        sound = Mix_LoadWAV("../data/son.wav");
        if (sound == nullptr)
          sound = Mix_LoadWAV("data/son.wav");
        if (sound == nullptr) {
                cout << "Failed to load son.wav :( SDL_mixer Error: " << Mix_GetError() << endl; 
                SDL_Quit();
                exit(1);
        }
    }

    //  // Chargement de la police de caractères
    // TTF_Font* font = TTF_OpenFont("chemin/vers/ma/police.ttf", 24);

    // // Création du texte du bouton
    // SDL_Color color = { 255, 255, 255 };
    // SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Mon bouton", color);

    // // Création de la texture du bouton
    // SDLSimple sdl;
    // sdl.buttonTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    // SDL_FreeSurface(textSurface);
}


SDLSimple::~SDLSimple () {
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/*SDLSimple::~SDLSimple (){

}*/

void SDLSimple::animation(int i) {
    char *M;
    if(i == 0){M = "data/go_1.png";}
    if(i == 1){M = "data/go_2.png";}
    if(i == 2){M = "data/go_3.png";}
    if(i == 3){M = "data/go_4.png";}
    if(i == 4){M = "data/go_5.png";}
    if(i == 5){M = "data/go_6.png";}
    if(i == 6){M = "data/go_7.png";}
    if(i == 7){M = "data/go_8.png";}
    if(i == 8){M = "data/go_9.png";}
    if(i == 9){M = "data/go_10.png";}

    im_zombi.loadFromFile(M,renderer);

    // SDL_Delay(50);

}

void SDLSimple::sdlAff () {

	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    //Afficher l'image du background
    im_plaine.draw(renderer,0,0,960,640);

	// Afficher le sprite du Zombi
    im_zombi.draw(renderer,jeu_sdl.tabEnnemi.at(0).splitX(),jeu_sdl.tabEnnemi.at(0).splitY(),TAILLE_SPRITE,TAILLE_SPRITE);
    im_zombi.draw(renderer,jeu_sdl.tabEnnemi.at(1).splitX(),jeu_sdl.tabEnnemi.at(1).splitY(),TAILLE_SPRITE,TAILLE_SPRITE);
    im_zombi.draw(renderer,jeu_sdl.tabEnnemi.at(2).splitX(),jeu_sdl.tabEnnemi.at(2).splitY(),TAILLE_SPRITE,TAILLE_SPRITE);

    // Afficher le spirte du batiment de défense
    //jeu_sdl.tabBatDef.at(0).setPosition(jeu_sdl.tabBatDef.at(0).getX()*2,jeu_sdl.tabBatDef.at(0).getY()*2);
    //jeu_sdl.tabBatDef.at(1).setPosition(jeu_sdl.tabBatDef.at(1).getX()*2,jeu_sdl.tabBatDef.at(1).getY()*2);

    for (unsigned int i = 0; i<jeu_sdl.tabBatDef.size();i++){
    im_batdef.draw(renderer,jeu_sdl.tabBatDef.at(i).splitX()*16,jeu_sdl.tabBatDef.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
    
    /*
	int x,y;
	const Terrain& ter = jeu.getConstTerrain();
	const Pacman& pac = jeu.getConstPacman();
	const Fantome& fan = jeu.getConstFantome();
    */

    // Afficher les sprites des murs et des pastilles
    /*
	for (x=0;x<ter.getDimX();++x)
		for (y=0;y<ter.getDimY();++y)
			if (ter.getXY(x,y)=='#')
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
			else if (ter.getXY(x,y)=='.')
				im_pastille.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
    */
	// Afficher le sprite de Pacman
	//im_pacman.draw(renderer,pac.getX()*TAILLE_SPRITE,pac.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite du Fantome
	//im_fantome.draw(renderer,fan.getX()*TAILLE_SPRITE,fan.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 270;positionTitre.y = 49;positionTitre.w = 100;positionTitre.h = 30;
    SDL_RenderCopy(renderer,font_im.getTexture(),nullptr,&positionTitre);

    // // Calcul des dimensions de la fenêtre
    // int windowWidth, windowHeight;
    // SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    // // Calcul des dimensions du bouton
    // int buttonWidth, buttonHeight;
    // SDL_QueryTexture(buttonTexture, NULL, NULL, &buttonWidth, &buttonHeight);

    // // Calcul des coordonnées x et y pour centrer le bouton
    // int x = (windowWidth - buttonWidth) / 2;
    // int y = (windowHeight - buttonHeight) / 2;

    // // Dessin du bouton sur le rendu de la fenêtre
    // SDL_Rect buttonRect = { x, y, buttonWidth, buttonHeight };
    // SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
    // SDL_RenderPresent(renderer);

}




void SDLSimple::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
    bool menu = false;

    Uint32 t = SDL_GetTicks(), nt;
    //Ennemi enm1;
    //Vect2 dir(0.5,0.5);
    //enm1.set_direction(dir);
    //jeu_sdl.tabEnnemi.clear();
    //jeu_sdl.tabEnnemi.push_back(enm1);

        BatimentDefense bat(TypeBatiment::Tourelle);

	// tant que ce n'est pas la fin ...
    Uint32 Time;
    Uint32 T;

    int i = 0;

    // while(!menu)
    // {
    //     sdlAff();
    // }

	while (!quit) {
        //jeu_sdl.deplacerEnnemis();
        jeu_sdl.tabEnnemi.at(0).deplacer();
        jeu_sdl.tabEnnemi.at(1).deplacer();
        jeu_sdl.tabEnnemi.at(2).deplacer();
        

        Time = SDL_GetTicks();
        T = (Time/1000);
        cout<<T<<endl;
        
        if (i > 9 ){i = 0;}
        animation(i);
        i++;

		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
				switch (events.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                    case SDL_SCANCODE_Q:
                    quit = true;
                    break;
			    default: break;
				}            
			}
            switch(events.type){
        case SDL_WINDOWEVENT:
            if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                quit != SDL_FALSE;
                break;
        case SDL_KEYDOWN:
            SDL_Log("+key");

            if (events.key.keysym.scancode == SDL_SCANCODE_W)
                SDL_Log("Scancode W");

            if (events.key.keysym.sym == SDLK_w)
                SDL_Log("Keycode W");

            if (events.key.keysym.sym == SDLK_z)
                SDL_Log("Keycode Z");

            break;
        case SDL_KEYUP: 
            SDL_Log("-key");
            break;
        case SDL_MOUSEMOTION: // Déplacement de souris
            SDL_Log("Mouvement de souris (%d %d) (%d %d)", events.motion.x, events.motion.y, events.motion.xrel, events.motion.yrel);
            break;
        case SDL_MOUSEBUTTONDOWN: // Click de souris 
            SDL_Log("+clic");
            jeu_sdl.tabBatDef.push_back(bat);
            jeu_sdl.tabBatDef.at(jeu_sdl.tabBatDef.size()-1).setPosition(events.motion.x/16,events.motion.y/21.33);
            break;
        case SDL_MOUSEBUTTONUP: // Click de souris relâché
            SDL_Log("-clic");
            break;
        case SDL_MOUSEWHEEL: // Scroll de la molette
            SDL_Log("wheel");
            break;
        }
		}        
    

       //Mix_PlayChannel(-1,sound,0);

		// on affiche le jeu sur le buffer cach�
		sdlAff();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}
