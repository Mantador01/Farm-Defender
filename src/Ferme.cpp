#include "Ferme.h"
#include <iostream>

using namespace std;

Ferme::Ferme(StockageRessources& stockage)
{
    m_stockage = &stockage;
    m_pointsDeVie = 20;
    pos.x = 0;
    pos.y = 0;
}





void Ferme::production(bool est_vivant)
{
    if(est_vivant){
    m_stockage->ajouterRessource("gold", 2);
    m_stockage->ajouterRessource("pierre", 2);
    m_stockage->ajouterRessource("bois", 2);
    m_stockage->ajouterRessource("nourriture", 2);}
}

void Ferme::degat(int degat)
{
    m_pointsDeVie -= degat;
}

bool Ferme::est_vivant()
{
    if(m_pointsDeVie<=0){
        return false;
    }else{return true;}
}

void Ferme::creation(Vect2 posi)
{
    m_pointsDeVie = 20;
    pos = posi;
}


Vect2 Ferme::get_position(){
    return pos;
}