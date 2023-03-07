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

const int XPntGenZSpw1 = 20 ;
const int YPntGenZSpw1 = 20 ;

const int XPntGenZSpw2 = 10 ;
const int YPntGenZSpw2 = 10 ;

const int XPntGenZSpw3 = 15 ;
const int YPntGenZSpw3 = 15 ;


/**
@brief Classe représentant un ennemi
*/

class Ennemi
{
private:
    bool statut; // 0 eliminé 1 vivant
    Type_ennemi type_en;
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


/**
@brief Constructeur avec paramètres: Initialise les valeurs de r, g et b avec les valeurs passées en paramètres
@param nr Valeur pour le canal rouge (0-255)
@param ng Valeur pour le canal vert (0-255)
@param nb Valeur pour le canal bleu (0-255)
*/


/**
@brief Accesseur pour le canal bleu
@return Valeur du canal bleu (0-255)
*/

#endif // ENNEMI_H
