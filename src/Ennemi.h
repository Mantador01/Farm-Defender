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

/**
@brief type ennumere pour identifier un ennemi
*/
enum Type_ennemi
{
    zombi,
    voleur
};

/**
@brief Classe représentant un ennemi
*/

Class Ennemi
{
public:
    bool statut; // 0 eliminé 1 vivant
    enum Type_ennemi type_en;
    int sante;
    int degat;
    t’es ou? à la bu, t ou ? en Arianne 4
    float vitesse;

//Direction
    Vect2 direction;
    Vect2 position;
//Vect2 Deplacement (const direction &dir);


    Ennemi();
    ~Ennemi();
private:
    void agir(); // gestion du déplacement, dégâts, sante …


}







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
