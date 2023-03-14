/**
@brief Description brève du fichier Ferme.h
Description détaillée du fichier Ferme.h
@author Alexandre
@file Ferme.h
@version 1.0
@date 07/03/2023
*/
/**
@brief Classe permettant la gestion des fermes.
*/

#ifndef FERME_H
#define FERME_H

#include "StockageRessources.h"
#include "Vect2.h"

using namespace std;

class Ferme {
public:
    Ferme();
    //Ferme(StockageRessources& stockage, int pointsDeVie);
    void production(bool est_vivant);
    void degat(int degat);
    bool est_vivant();
private:
    StockageRessources& m_stockage;
    int m_pointsDeVie;
    Vect2 pos;
};

#endif // FERME_H