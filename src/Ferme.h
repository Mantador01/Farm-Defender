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
#include <thread>
#include <atomic>

using namespace std;

class Ferme {
public:
    Ferme(StockageRessources& stockage, int pointsDeVie);
    void demarrerProduction();
    void arreterProduction();
private:
    void production();
    StockageRessources& m_stockage;
    int m_pointsDeVie;
    thread m_threadProduction;
    atomic<bool> m_productionActive;
};

#endif // FERME_H