    /**
    @brief Description brève du fichier JeuModeGraphique.h
    Description détaillée du fichier JeuModeGraphique.h
    @author P2111020/P2018147/P2105542
    @file JeuModeGraphique.h
    @version 1.0
    @date 07/03/2023
    */

    #ifndef JEUMODEGRAPHIQUE_H
    #define JEUMODEGRAPHIQUE_H

    #include "Jeu.h"

    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>

    class Image {

    private:

        SDL_Surface * m_surface;
        SDL_Texture * m_texture;
        bool m_hasChanged;

    public:
        Image () ;
        ~Image();
        void loadFromFile (const char* filename, SDL_Renderer * renderer);
        void loadFromCurrentSurface (SDL_Renderer * renderer);
        void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
        SDL_Texture * getTexture() const;
        void setSurface(SDL_Surface * surf);
};

    /**
    @brief Classe résponsable de l'affichage
    */
    class JeuModeGraphique
    {
        public:
            JeuModeGraphique ();
            ~JeuModeGraphique ();
            void sdlBoucle ();
            void sdlAff ();

        private:
            Jeu jeu;

            SDL_Window * window;
            SDL_Renderer * renderer;

            TTF_Font * font;
            Image font_im;
            SDL_Color font_color;

            Mix_Chunk * sound;
            bool withSound;

            Image im_zombi;
            Image im_plaine;

            bool souris;
            bool touche;
    };
    #endif