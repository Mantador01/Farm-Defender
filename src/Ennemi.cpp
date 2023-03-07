#include "Vect2.h"
#include "Ennemi.h"

using namespace std;

void Ennemi::Deplacer()
{
    position=position+direction*vitesse;
    //faire tests
}

void Ennemi::enleverSante(int points_enleves){
    if(statut=true)
    {
        sante=sante-points_enleves;
        if(sante<=0)
        {
            statut=false;
        }
    }
}
