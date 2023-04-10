#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <X11/Xlib.h>



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

    Display *display = XOpenDisplay(nullptr);
    Screen *screen = DefaultScreenOfDisplay(display);
    
    const int screenWidth = screen->width;
    const int screenHeight = screen->height;

	jeu_sdl.jeu_hauteur = screenWidth;
    jeu_sdl.jeu_largeur = screenHeight;

    XCloseDisplay(display);

	cout<<" SDL COUT : "<< jeu_sdl.jeu_hauteur<< " " << jeu_sdl.jeu_largeur <<endl;
    // Creation de la fenetre
    window = SDL_CreateWindow("FarmDefender", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, jeu_sdl.jeu_hauteur, jeu_sdl.jeu_largeur, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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
    /*
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}
    */
    
    /*
	font_color.r = 50;font_color.g = 50;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"Pacman",font_color));
	font_im.loadFromCurrentSurface(renderer);
    */

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

}


SDLSimple::~SDLSimple () {
    if (withSound) Mix_Quit();
    //TTF_CloseFont(font);
    //TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/*SDLSimple::~SDLSimple (){

}*/

void SDLSimple::sdlAff () {

	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    //Afficher l'image du background
    im_plaine.draw(renderer,0,0,jeu_sdl.jeu_largeur,jeu_sdl.jeu_hauteur);

	// Afficher le sprite du Zombi
    im_zombi.draw(renderer,jeu_sdl.tabEnnemi.at(0).splitX(),jeu_sdl.tabEnnemi.at(0).splitY(),TAILLE_SPRITE,TAILLE_SPRITE);
    im_zombi.draw(renderer,jeu_sdl.tabEnnemi.at(1).splitX(),jeu_sdl.tabEnnemi.at(1).splitY(),TAILLE_SPRITE,TAILLE_SPRITE);
    im_zombi.draw(renderer,jeu_sdl.tabEnnemi.at(2).splitX(),jeu_sdl.tabEnnemi.at(2).splitY(),TAILLE_SPRITE,TAILLE_SPRITE);

    // Afficher le spirte du batiment de défense
    im_batdef.draw(renderer,jeu_sdl.tabBatDef.at(0).splitX(),jeu_sdl.tabBatDef.at(0).splitY(),TAILLE_SPRITE*3,TAILLE_SPRITE*3);

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
    //SDL_Rect positionTitre;
    //positionTitre.x = 270;positionTitre.y = 49;positionTitre.w = 100;positionTitre.h = 30;
    //SDL_RenderCopy(renderer,font_im.getTexture(),nullptr,&positionTitre);

}


void SDLSimple::sdlBoucle () {
    SDL_Event events;
	bool quit = false;

    Uint32 t = SDL_GetTicks(), nt;
    //Ennemi enm1;
    //Vect2 dir(0.5,0.5);
    //enm1.set_direction(dir);
    //jeu_sdl.tabEnnemi.clear();
    //jeu_sdl.tabEnnemi.push_back(enm1);

	// tant que ce n'est pas la fin ...
	while (!quit) {
        //jeu_sdl.deplacerEnnemis();
        jeu_sdl.tabEnnemi.at(0).deplacer();
        jeu_sdl.tabEnnemi.at(1).deplacer();
        jeu_sdl.tabEnnemi.at(2).deplacer();
        /*
        nt = SDL_GetTicks();
        if (nt-t>500) {
            jeu.actionsAutomatiques();
            t = nt;
        }
        */

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
		}

       //// Mix_PlayChannel(-1,sound,0);

		// on affiche le jeu sur le buffer cach�
		sdlAff();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}
