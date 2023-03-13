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
#include <thread>
#include <atomic>

using namespace std;

class BaseCentrale {
public:
    BaseCentrale(StockageRessources& stockage, int pointsDeVie);
    void demarrerProduction();
    void arreterProduction();
private:
    void production();
    StockageRessources& m_stockage;
    int m_pointsDeVie;
    thread m_threadProduction;
    atomic<bool> m_productionActive;
};

#endif // BaseCentrale_H