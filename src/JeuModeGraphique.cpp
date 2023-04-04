#include "JeuModeGraphique.h"
#include "sdlJeu.h"
#include <iostream>
#include <X11/Xlib.h>

using namespace std;
int main (int argc, char** argv) {

	

	Display *display = XOpenDisplay(nullptr);
    Screen *screen = DefaultScreenOfDisplay(display);
    
    const int screenWidth = screen->width;
    const int screenHeight = screen->height;
    
    cout << "La résolution de l'écran est de " << screenWidth << "x" << screenHeight << std::endl;

	

	// SDL.jeu_sdl.jeu_largeur = 500;
    // SDL.jeu_sdl.jeu_hauteur = 500;


    XCloseDisplay(display);
	SDLSimple sj;
	cout<<" constructeur : "<< sj.jeu_sdl.jeu_hauteur<< " " << sj.jeu_sdl.jeu_largeur <<endl;

	sj.jeu_sdl.jeu_largeur = screenWidth;
    sj.jeu_sdl.jeu_hauteur = screenHeight;

	cout<<" modif : "<< sj.jeu_sdl.jeu_hauteur<< " " << sj.jeu_sdl.jeu_largeur <<endl;

	sj.sdlBoucle();
	return 0;
}
