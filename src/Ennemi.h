/**
@brief Description brève du fichier Ennemi.h
Description détaillée du fichier Ennemi.h
@author P2105542
@file Ennemi.h
@version 1.0
@date 2023/03/07
*/

#ifndef ENNEMI_H
#define ENNEMI_H

#include "Vect2.h"
#include <stdlib.h>
/**
@brief type ennumere pour identifier un ennemi
*/
enum Type_ennemi
{
    zombi,
    z_infectieu,
    z_berserker,
    pillard
};

const float XPntGenZSpw1 = 20 ;
const float YPntGenZSpw1 = 20 ;

const float XPntGenZSpw2 = 10 ;
const float YPntGenZSpw2 = 10 ;

const float XPntGenZSpw3 = 15 ;
const float YPntGenZSpw3 = 15 ;


/**
@brief Classe représentant un ennemi
*/

class Ennemi
{
private:
    bool statut; // 0 eliminé 1 vivant
    enum Type_ennemi type_en;
    int sante;
    int degat;
    float vitesse;

//Direction
    Vect2 direction;
    Vect2 position;


public:
    Ennemi();
    ~Ennemi();

    /**
    @brief Constructeur Ennemi avec paramètres
    Initialise les champs avec les valeurs passées en paramètres
    @param dimensionY Hauteur de l'image
    */
    Ennemi(Type_ennemi typeEnnemi);

    /**
    @brief Deplace l ennemi selon la position et sa dirrection
    Remplit les pixels du rectangle avec la couleur spécifiée
    */
    void Deplacer();
    // un tableu qiu repertorie toutes les positions des obstacles pour les ennemis

    /**
    @brief enleverVide eleve points_enleves des points de sante et si ce champ et met a jour le statut
    @param points_enleves int points a enlever de l ennemi
    */
    void enleverSante(int points_enleves);
    /**
    @brief Accesseur pour degat
    @return valeur du degat cause par ennemi
    */
    int get_degat();
    void agir(); // gestion du déplacement, dégâts, sante …

};


#endif // ENNEMI_H
