#include "BaseCentrale.h"
#include <iostream>

using namespace std;

BaseCentrale::BaseCentrale(StockageRessources& stockage, int pointsDeVie)
    : m_stockage(stockage), m_pointsDeVie(pointsDeVie){}


void BaseCentrale::production()
{
    if(m_pointsDeVie>0){
    m_stockage.ajouterRessource("gold", 10);
    m_stockage.ajouterRessource("pierre", 10);
    m_stockage.ajouterRessource("bois", 10);
    m_stockage.ajouterRessource("nourriture", 10);}
}

void BaseCentrale::degat(int degat)
{
    m_pointsDeVie -= degat;
}

