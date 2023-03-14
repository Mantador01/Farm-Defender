/**
@brief Description brève du fichier BaseCentrale.h
Description détaillée du fichier BaseCentrale.h
@author Alexandre
@file BaseCentrale.h
@version 1.0
@date 07/03/2023
*/
/**
@brief Classe permettant la gestion des BaseCentrales.
*/

#ifndef BaseCentrale_H
#define BaseCentrale_H

#include "StockageRessources.h"
#include "Vect2.h"

using namespace std;

class BaseCentrale {
public:
    // BaseCentrale(StockageRessources& stockage, int pointsDeVie);
    BaseCentrale();
    void production(bool est_vivant);
    void degat(int degat);
private:
    StockageRessources m_stockage;
    int m_pointsDeVie;
    Vect2 pos;
};

#endif // BaseCentrale_H