/**
@brief Description brève du fichier Vague.h
Description détaillée du fichier Vague.h
@author Alexandre
@file Vague.h
@version 1.0
@date 07/03/2023
*/

#ifndef VAGUE_H
#define VAGUE_H

#include "Jeu.h"
#include "Ennemi.h"
/**
@brief Classe gérant les vagues d'ennemis.
*/

class Vague

{
    public:

        /**
        @brief Constructeur par défaut: Initialise les vagues.
        */
        Vague();

        /**
        @brief Destructeur de la classe Vague
        */
        ~Vague();

        /**
        @brief Timer de la classe Vect2
        Permet d'obtenir le moment T.*/
        float Timer()const;

        /**
        @brief DeclancheVague de la classe Vect2
        Permet de déclancher la vague.
        @param Vague a, la vague a déclancher.*/
        DeclancheVague (Vague a);


    private:

    /**
    @brief Initialiseur des vagues.
    */
    enum type_ennemi tab_type[];
    int ennemi_N[];
};

#endif // Vague_H
