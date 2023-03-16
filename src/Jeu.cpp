#include "Jeu.h"

#include <iostream>
#include <vector>
using namespace std;

Jeu::Jeu(){

    jeu_largeur=40; jeu_hauteur=20;
}

Jeu::~Jeu(){

}

void Jeu::deplacerEnnemis(){


  //  (std::vector<Ennemi> & tabEnnemi,vector<BatimentDefense> tabBatDef, vector<Ferme> TabFerme,BaseCentrale baseCentrale


    long unsigned int e,bat,ferme;
    long unsigned int indiceMinDistance;
    long unsigned int indiceBatdegat;
    float distanceActuelle,distanceMinimale;
    bool batProche,deplacerEnnemiBool;
    Ennemi enboucle;
    Vect2 posEnne,posBati;
    BatimentDefense bati;
    //Ferme ferme1;

    for(e=0;e<tabEnnemi.size();e++)
    {
        batProche=false;
        enboucle=tabEnnemi.at(e);
        posEnne= enboucle.get_position();
        deplacerEnnemiBool=true;

        for(bat=0;bat<tabBatDef.size();bat++)
        {
            if(deplacerEnnemiBool==true){

            }
            if(bat==0){distanceMinimale=posEnne.distance(posBati); indiceMinDistance=0;}
            bati=tabBatDef.at(bat);
            posBati=bati.getPosition();
            distanceActuelle=posEnne.distance(posBati);//tabEnnemi.po
            if(distanceActuelle<2.f)
            {
                batProche=true;
                cout<<batProche<<"bat proche";
                if(distanceActuelle<distanceMinimale)
                {
                    distanceMinimale=distanceActuelle;
                    indiceMinDistance=bat;
                    cout<<indiceMinDistance;
                    if(distanceMinimale<0.2) //ennemi est assez proche pour attaquer le batiment
                    {
                    deplacerEnnemiBool=false;
                    indiceBatdegat=bat;
                    cout<<indiceBatdegat<<" : indiceBatdegat  ";

                    //ennemi fait des degats au batiment    
                    }
                }


            }
        }

        if(deplacerEnnemiBool==true)
        {
            Vect2 posActuelle=tabEnnemi.at(e).get_position();
             
            if( posActuelle.x> 0 || posActuelle.x<20 || posActuelle.y>0 || posActuelle.y<20)
            {
                tabEnnemi.at(e).deplacer();
            }
            
        }


        /// enboucle est une copie l'enemi actuel 
        deplacerEnnemiBool=true;
        
        for(ferme=0;ferme<TabFerme.size();ferme++)
        {
           /* //ferme1=TabFerme.at(bat);
            posBati=bati.getPosition();
            distanceActuelle=posEnne.distance(posBati);//tabEnnemi.po

            if(distanceActuelle<1.f)
            {
                        faire des degats dans les fermes

            }*/
        }

    ///
        //bool test = true;
        /*if(deplacerEnnemiBool==true){
            //if(batProche==true) ///l'ennemi va etre devié vers le batiment le plus proche
            {
                //Vect2 nouveauDepl;
                //bati=tabBatDef.at(indiceMinDistance);
                //posBati=bati.getPosition();
                //nouveauDepl=posBati-posEnne;
                //nouveauDepl=nouveauDepl*(1/2);
            }

            //tabEnnemi.at(e).deplacer();

       // }else{
           // std::cout<<indiceBatdegat;
            ///if faut faire des degats dans le bat a l'indice indiceBatdegat

      //  }

        ////*/

 

    }

}