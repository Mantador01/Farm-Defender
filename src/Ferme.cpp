#include "Ferme.h"
#include <iostream>

using namespace std;

Ferme::Ferme(StockageRessources& stockage, int pointsDeVie)
    : m_stockage(stockage), m_pointsDeVie(pointsDeVie){}


void Ferme::production()
{
    if(m_pointsDeVie>0){
    m_stockage.ajouterRessource("gold", 2);
    m_stockage.ajouterRessource("pierre", 2);
    m_stockage.ajouterRessource("bois", 2);
    m_stockage.ajouterRessource("nourriture", 2);}
}

void Ferme::degat(int degat)
{
    m_pointsDeVie -= degat;
<<<<<<< HEAD
}
=======
}
>>>>>>> 33ea55cbc7a5d94733ac0e18b259da0db2aac446
