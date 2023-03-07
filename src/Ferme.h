/**
@brief Description brève du fichier Ferme.h
Description détaillée du fichier Ferme.h
@author Alexandre
@file Ferme.h
@version 1.0
@date 07/03/2023
*/

#ifndef FERME_H
#define FERME_H

#include "Vect2.h"

/**
@brief Classe permettant la gestion des fermes.
*/

class Ferme

{
    public:

        /**
        @brief Constructeur par défaut: Initialise les paramètres des fermes a 0.
        */
        Ferme();

        /**
        @brief Destructeur de la classe Ferme
        */
        ~Ferme();

        /**
        @brief Fonction d'actualisation des productions de la classe Ferme
        Permet de stocker les ressources.*/
        int actualise_production();

        /**
        @brief Fonction de gestion des dégats de la classe Ferme
        Permet de gérer les dégats que prend les fermes.*/
        int gestion_degats(int degat);

    private:

    /**
    @brief Booléen pour le statut.
    */
    bool statut;

    /**
    @brief Entier pour la santé.
    */
    int sante;

    /**
    @brief Entier pour la fréquence de production.
    */
    int production;

    /**
    @brief Entier pour le stockage de la production.
    */
    int Stockage_local;

    /**
    @brief Vecteur de position.
    */
    Vect2 position;
};

#endif // FERME_H
