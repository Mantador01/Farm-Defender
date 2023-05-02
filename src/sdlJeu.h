    /**
    @brief Description brève du fichier sdlJeu.h
    Description détaillée du fichier sdlJeu.h
    @author Ahmed/Alexandre/Sara
    @file sdlJeu.h
    @version 1.0
    @date 01/05/2023
    */   

#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Jeu.h"




/**
@brief Classe représentant une image SDL à partir d'une surface et d'une texture
*/
class Image {
private:
SDL_Surface * m_surface; /**< Surface SDL de l'image */
SDL_Texture * m_texture; /**< Texture SDL de l'image */
bool m_hasChanged; /**< Booléen indiquant si l'image a été modifiée*/

public:
/**
@brief Constructeur par défaut: Initialise les attributs de l'image à NULL et false
*/
Image () ;

/**
@brief Destructeur de la classe Image
Libère la mémoire allouée pour la surface et la texture SDL
*/
~Image();

/**
@brief Charge une image à partir d'un fichier et crée une texture SDL
@param filename Chemin d'accès du fichier de l'image
@param renderer Pointeur vers le renderer SDL pour créer la texture
*/
void loadFromFile (const char* filename, SDL_Renderer * renderer);

/**
@brief Charge la texture SDL à partir de la surface SDL de l'image
@param renderer Pointeur vers le renderer SDL pour créer la texture
*/
void loadFromCurrentSurface (SDL_Renderer * renderer);

/**
@brief Dessine l'image sur le renderer SDL à partir de sa texture
@param renderer Pointeur vers le renderer SDL
@param x Coordonnée x du coin supérieur gauche de l'image
@param y Coordonnée y du coin supérieur gauche de l'image
@param w Largeur de l'image (optionnel, -1 par défaut pour la taille de la texture)
@param h Hauteur de l'image (optionnel, -1 par défaut pour la taille de la texture)
*/
void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);

/**
@brief Retourne la texture SDL de l'image
@return Pointeur vers la texture SDL de l'image
*/
SDL_Texture * getTexture() const;

/**
@brief Modifie la surface SDL de l'image
@param surf Pointeur vers la nouvelle surface SDL de l'image
*/
void setSurface(SDL_Surface * surf);


};

/**
@brief Classe représentant une fenêtre SDL, un renderer et diverses images, sons et options pour un jeu
*/
class SDLSimple {
private:
SDL_Window * window; /**< Fenêtre SDL du jeu */
SDL_Renderer * renderer; /**< Renderer SDL du jeu */

TTF_Font * font; /**< Police de caractères SDL */
Image font_im; /**< Image SDL pour le texte */
SDL_Color font_color; /**< Couleur du texte */

Mix_Chunk * sound; /**< Effet sonore SDL 1 */
Mix_Chunk * sound2; /**< Effet sonore SDL 2 */

bool withSound; /**< Booléen indiquant si les effets sonores sont activés*/

    Image im_zombi;
    Image im_plaine;
    Image im_batdef;
    Image im_go1;
    Image im_go2;
    Image im_go3;
    Image im_go4;
    Image im_go5;
    Image im_go6;
    Image im_go7;
    Image im_go8;
    Image im_go9;
    Image im_go10;
    Image im_menu1;
    Image im_Option1;
    Image im_Option2;
    Image im_Option3;
    Image im_Credit;

bool souris; /**< Booléen indiquant si la souris est enfoncée */
bool touche; /**< Booléen indiquant si une touche est enfoncée */

SDL_Texture* buttonTexture; /**< Texture du bouton */
int inc; /**< Incrémentation utilisée dans la fonction sdlBoucle() */

Jeu jeu_sdl; /**< Instance de la classe Jeu utilisée pour gérer la logique du jeu */

public :

/**
@brief Constructeur par défaut de la classe SDLSimple
*/
SDLSimple ();

/**
@brief Destructeur de la classe SDLSimple
*/
~SDLSimple ();

/**
@brief Fonction principale de la boucle de jeu en SDL
*/
void sdlBoucle ();

/**
@brief Fonction affichant les éléments graphiques de la boucle de jeu en SDL
*/
void sdlAff ();

/**
@brief Fonction affichant le menu principal en SDL
*/
void sdlMenu ();

/**
@brief Fonction affichant les options en SDL
@param img Indique l'image à afficher
*/
void sdlOption(int img);

/**
@brief Fonction affichant les crédits en SDL
*/
void sdlCredit();

};

#endif