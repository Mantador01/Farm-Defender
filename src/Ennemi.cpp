/**
@brief Description brève du fichier Ennemi.cpp
Description détaillée du fichier Ennemi.cpp
@author P2105542
@file Ennemi.cpp
@version 1.0
@date 2023/03/07
*/


#include "Vect2.h"
#include "Ennemi.h"
#include <iostream>
#include <stdlib.h>

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
    switch(r){
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;
                    break;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;
                    break;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;
                    break;}
        }
        cout<<X+((float)(rand()%21-10))<<" x  "<<endl;
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
    Vect2 dir(10.f,-10.f);
    direction=dir;
    }
}

Ennemi::Ennemi(Type_ennemi typeENnemi){
    statut=true;
    type_en=typeENnemi;
    if (type_en==zombi)
    {
        sante=10;
        degat=1;
        vitesse=1;
        int r=rand()%3;
        float X,Y;
        switch(r){
            case 0: {X=XPntGenZSpw1; Y=YPntGenZSpw1;
                    break;}
            case 1: {X=XPntGenZSpw2; Y=YPntGenZSpw2;
                    break;}
            case 2: {X=XPntGenZSpw3; Y=YPntGenZSpw3;
                    break;}
        }

    }
  //  position=Vect2(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10));
   // diretion=Vect2(10.f,-10.f);
}

/*
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

*/
