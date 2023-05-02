    /**
    @brief Description brève du fichier Vect2.h
    Description détaillée du fichier Vect2.h
    @author Ahmed/Alexandre/Sara
    @file Vect2.h
    @version 1.0
    @date 01/05/2023
    */ 


#ifndef VECT2_H
#define VECT2_H

#include <iostream>
#include <ostream>



/**
@brief Classe représentant un vecteur 2D
*/
class Vect2
{
public:

/**
@brief Constructeur par défaut: Initialise les coordonnées du vecteur à 0
*/
Vect2();

/**
@brief Destructeur de la classe Vect2
*/
~Vect2();

/**
@brief Constructeur avec paramètres
Initialise les coordonnées du vecteur avec les valeurs passées en paramètres
@param a Coordonnée x du vecteur
@param b Coordonnée y du vecteur
*/
Vect2(float a, float b);

/**
@brief Surcharge de l'opérateur '+'
Additionne le vecteur courant avec le vecteur passé en paramètre
@param a Vecteur à additionner
@return Le résultat de l'addition des deux vecteurs
*/
Vect2 operator+ (Vect2 a);

/**
@brief Surcharge de l'opérateur '-'
Soustrait le vecteur courant avec le vecteur passé en paramètre
@param a Vecteur à soustraire
@return Le résultat de la soustraction des deux vecteurs
*/
Vect2 operator- (Vect2 a);

/**
@brief Surcharge de l'opérateur '*'
Multiplie le vecteur courant par le scalaire passé en paramètre
@param a Scalaire à multiplier avec le vecteur
@return Le résultat de la multiplication du vecteur par le scalaire
*/
Vect2 operator* (float a);

/**
@brief Fonction qui crée un nouveau vecteur 2D avec les coordonnées passées en paramètre
@param a Coordonnée x du vecteur
@param b Coordonnée y du vecteur
@return Le nouveau vecteur créé
*/
Vect2 make_Vect2 (float a, float b);

/**
@brief Calcule la distance entre le vecteur courant et le vecteur passé en paramètre
@param a Vecteur dont on veut calculer la distance
@return La distance entre le vecteur courant et le vecteur passé en paramètre
*/
float distance (Vect2 a);

/**
@brief Coordonnée x du vecteur
*/
float x;

/**
@brief Coordonnée y du vecteur
*/
float y;

/**
@brief Normalise le vecteur courant
*/
void normailiser();


private:
};

#endif