/**
@brief Description brève du fichier Vect2.h
Description détaillée du fichier Vect2.h
@author Alexandre
@file Vect2.h
@version 1.0
@date 07/03/2023
*/

#ifndef VECT2_H
#define VECT2_H

#include <iostream>
#include <ostream>

/**
@brief Classe permettant le positionnement des éléments.
*/

class Vect2

{
    public:

        /**
        @brief Constructeur par défaut: Initialise la position de base a 0.
        */
        Vect2();

        /**
        @brief Destructeur de la classe Vect2
        Libère la mémoire allouée pour le tableau de Vecteur.
        */
<<<<<<< HEAD
        ~Vect2();   

        //void Vect2::operator = (Vect2 a);
=======
        ~Vect2();
        
        
                /**
        @brief constructeur de vecteur de la classe Vect2
        Permet la construction de vecteurs a partir de 2 réels.
        @param float a premier réel pour la création du vecteur.
        @param float b deuxième réel pour la création du vecteur.*/
        Vect2(float a, float b);
>>>>>>> e7ce9f5fcafaee73dfa4434000534f38551f1829

        /**
        @brief Operateur + de la classe Vect2
        Permet l'addition entre vecteurs.
        @param Vecteur a additionner.*/
        Vect2 operator+ (Vect2 a);

        /**
        @brief Operateur - de la classe Vect2
        Permet la soustraction entre vecteurs.
        @param Vecteur a soustraire.*/
        Vect2 operator- (Vect2 a);

        /**
        @brief Operateur * de la classe Vect2
        Permet la multiplication entre un vecteur et un float.
        @param float a multiplier.*/
        Vect2 operator* (float a);

        /**
        @brief constructeur de vecteur de la classe Vect2
        Permet la construction de vecteurs a partir de 2 réels.
        @param float a premier réel pour la création du vecteur.
        @param float b deuxième réel pour la création du vecteur.*/
        Vect2 make_Vect2 (float a, float b);


        /**
        @brief calcul de la distance de la classe Vect2
        Permet le calcule de la distance entre 2 vecteurs.
        @param Vecteur a première coordonner pour le calcul de la distance.
        @param Vecteur b deuxième coordonner pour le calcul de la distance.*/
        float distance (Vect2 a, Vect2 b);

        /**
        @brief Initialiseur des réels x et y
        */
        float x,y;
        
    private:

};

#endif // VECT2_H
