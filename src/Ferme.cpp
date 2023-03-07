#include "Ferme.h"
#include "Vect2.h"

#include <iostream>
#include <math.h>
#include <unistd.h>

using namespace std;

Ferme::Ferme()
{
    statut = true;
    sante = 100;
    production = 20;
    position.x = 0;
    position.y = 0;    
}

Ferme::~Ferme()
{
}

int Ferme::actualise_production()
{
    while (statut)
    {
        Stockage_local += production;
        sleep(20);
    }
}

int Ferme::gestion_degats(int degat)
{
    sante = sante - degat;
    if (sante <= 0){
        statut = false;
    }
}