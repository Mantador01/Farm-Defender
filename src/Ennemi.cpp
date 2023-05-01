


#include "Vect2.h"
#include "Ennemi.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

const float XPntGenZSpw1 = 20 ;
const float YPntGenZSpw1 = 20 ;

const float XPntGenZSpw2 = 10 ;
const float YPntGenZSpw2 = 10 ;

const float XPntGenZSpw3 = 15 ;
const float YPntGenZSpw3 = 15 ;


Ennemi::Ennemi()
{   statut=true;
    temps_mort=0;
    type_en=zombi;
    sante=10;
    degat=5;     vitesse=0.08;     if (type_en==zombi){
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
            Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
    Vect2 dir(10.f,-10.f);
    direction=dir;
    }
}



int Ennemi::get_degat()
{
	return degat;
}

Type_ennemi Ennemi::getType()const{
return type_en;
}



void Ennemi::deplacer()
{
    position=position+direction*(vitesse*2/3);
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


Ennemi::~Ennemi()
{
    }

Vect2 Ennemi::get_position()
{
	return position;
}

void Ennemi::set_pos(Vect2 posi)
{
    position=posi;
}

void Ennemi::set_direction(Vect2 dir){
    direction=dir;

}

int Ennemi::get_sante(){
    return sante;
}

void Ennemi::afficher()
{
    cout << "Type ennemi: " <<this->getType() <<endl;
    cout << "Sante ennemi: " <<this->get_sante() <<endl;
}


bool Ennemi::get_statut(){
    return statut;
}

float Ennemi::splitX()
{
    return position.x;
}

float Ennemi::splitY()
{
    return position.y;
}

Ennemi::Ennemi(Type_ennemi typeENnemi){
    statut=true;
    temps_mort=0;
    type_en=typeENnemi;
	Vect2 dir(10.f,-10.f);
    direction=dir;
    
    
    
    if (type_en==zombi)
    {
        sante=10;
        degat=1;
        vitesse=0.08;
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
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
    }
	if(type_en==z_infectieu){
		sante=10;
        degat=2;
        vitesse=0.05;
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
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
	}
	if(type_en==z_berserker){
		sante=10;
        degat=2;
        vitesse=0.4;
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
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
	}
	if(type_en==pillard){
		sante=10;
        degat=3;
        vitesse=0.04;
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
    Vect2 pos(X+((float)(rand()%21-10)),Y+((float)(rand()%21-10)));
    position=pos;
	}
    
}

float Ennemi::get_temps_mort(){
    return temps_mort;
}

void Ennemi::add_temps_mort(float tempsMort){
    temps_mort=temps_mort+tempsMort;
}
