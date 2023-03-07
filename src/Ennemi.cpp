#include "Vect2.h"
#include "Ennemi.h"

using namespace std;



Ennemi::Ennemi()
{   statut=true;
    type_en=zombi;
    sante=10;
    degat=1;
    vitesse=1;
    if (type_en==zombi){
        int r=rand()%3;
        float X,Y;
        switch(t):
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;}
    }
    position=Vect2(X+(rand()%21-10),Y+(rand()%21-10));
    diretion=Vect2(10,-10);
}

Ennemi::Ennemi(Type_ennemi typeEnnemi){
    statut=true;
    type_en=typeEnnemi;
    if (type_en==zombi)
    {
        sante=10;
        degat=1;
        vitesse=1;
        int r=rand()%3;
        float X,Y;
        switch(t):
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;}
    }
    position=Vect2(X+(rand()%21-10),Y+(rand()%21-10));
    diretion=Vect2(10,-10);
}


void Ennemi::Deplacer()
{
    position=position+direction*vitesse;
    //faire tests avec le tableau de batiments
}

void Ennemi::enleverSante(int points_enleves){
    if(statut==true)
    {
        sante=sante-points_enleves;
        if(sante<=0)
        {
            statut=false;
        }
    }
}

