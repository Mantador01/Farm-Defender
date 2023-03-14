/**
@brief Description brève du fichier BaseCentrale.h
Description détaillée du fichier BaseCentrale.h
@author Alexandre
@file BaseCentrale.h
@version 1.0
@date 14/03/2023
*/
/**
@brief Classe permettant la gestion de la BaseCentrale.
*/

#ifndef BaseCentrale_H
#define BaseCentrale_H

#include "StockageRessources.h"
#include "Vect2.h"

using namespace std;

class BaseCentrale {
public:

    /**
    @brief Constructeur par défaut: Initialise la position de base a 0, définie les points de vie a 200 et le connecte au stockage de la classe StockageRessources.
    */
    BaseCentrale();

    /**
    @brief Fonction production qui incrémente les ressources de 10 a chaques appels de cette fonction seulement si la BaseCentrale est vivante.
    @param Booléen : est_vivant renvoie true si la ferme est toujour vivante(vie>0) false sinon.
    */
    void production(bool est_vivant);

    /**
    @brief Fonction degat qui permet de soustraire les dégats passer en paramètre et la vie de la BaseCentrale.
    @param Entier : degat les dégats a soustraire a la vie.
    */
    void degat(int degat);

    bool est_vivant();

    int m_carac;

    int m_size;
    
    /**
    @param Vect2 : pos la position de la BaseCentrale.
    */
    Vect2 pos;

    void setPos (int x, int y);

private:
    /**
    @param StockageRessources : m_stockage le stockage des ressources que produiront la BaseCentrale.
    */
    StockageRessources m_stockage;

    /**
    @param Entier : m_pointsDeVie la vie de la BaseCentrale.
    */
    int m_pointsDeVie;

};

#endif // BaseCentrale_H