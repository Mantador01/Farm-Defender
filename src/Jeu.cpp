#include "Jeu.h"
#include <unistd.h> //sleep?
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
   // enleveEntDestruites();

    long unsigned int e,bat,ferme;
    long unsigned int indiceMinDistance;
    long unsigned int indiceBatdegat;
    float distanceActuelle,distanceMinimale;
    bool batProche,deplacerEnnemiBool;
    Ennemi enboucle;
    Vect2 posEnne,posBati;
    BatimentDefense bati;

    StockageRessources stockage;
    Ferme ferme1(stockage);
    Vect2 pos(0,0);
    ferme1.creation(pos);

    for(e=0;e<tabEnnemi.size();e++)  //<
    { 
    cout<<"indice ennemi "<<e<<"  ";
        batProche=false;
        enboucle=tabEnnemi.at(e);
        posEnne= enboucle.get_position();
        deplacerEnnemiBool=true;
        
        distanceMinimale=posEnne.distance(posBati); 
        indiceMinDistance=0;
        
        if(tabBatDef.size()>0){
        for(bat=0;bat<tabBatDef.size();bat++) //test proximité des batiments
        {   cout<<"indice bat "<<bat;
            if(bat==0){distanceMinimale=posEnne.distance(posBati); indiceMinDistance=0;}
            bati=tabBatDef.at(bat);
            posBati=bati.getPosition();
            distanceActuelle=posEnne.distance(posBati);//tabEnnemi.po
            if(distanceActuelle<200.f)  //if(distanceActuelle<2.f)
            {
                batProche=true;
                cout<<batProche<<"bat proche pour ennemi num :"<<e<<" ";
                if(distanceActuelle<distanceMinimale)
                {
                    distanceMinimale=distanceActuelle;
                    indiceMinDistance=bat;
                    //cout<<indiceMinDistance;
                    if(distanceMinimale<0.1) //ennemi est assez proche pour attaquer le batiment
                    {
                    deplacerEnnemiBool=false;
                    indiceBatdegat=bat;
                    //cout<<indiceBatdegat<<" : indiceBatdegat  ";

                    //ennemi fait des degats au batiment    
                    }
                }


            }
        }
        }

        
        //bool test = true;
        if(deplacerEnnemiBool==true){

            if(batProche==true) ///l'ennemi va etre devié vers le batiment le plus proche
            {
                //float distance_pour_normaliser;
                Vect2 nouveauDepl;
                //bati=tabBatDef.at(indiceMinDistance);
                posBati=tabBatDef.at(indiceMinDistance).getPosition();
                //distance_pour_normaliser=posBati.distance(posEnne);
                nouveauDepl=posBati-posEnne;
                //nouveauDepl=nouveauDepl*(1/distance_pour_normaliser);
                nouveauDepl.normailiser();

                tabEnnemi.at(e).set_direction(nouveauDepl);
                cout<<"devié ver bat proche";
                //normaliser

                //nouveauDepl=nouveauDepl*(1/2);
            }

            //tabEnnemi.at(e).deplacer();

       }else{
           // std::cout<<indiceBatdegat;
            ///if faut faire des degats dans le bat a l'indice indiceBatdegat
            //cout<<"ennemi indice "<<e<<"   se deplace"<<endl;
            tabBatDef.at(indiceBatdegat).enleverPointsVie(enboucle.get_degat());
            //cout<<"degat "<<enboucle.get_degat()<<endl;

       }

        ////*/




        if(deplacerEnnemiBool==true)
        {
            Vect2 posActuelle=tabEnnemi.at(e).get_position();
            if( (posActuelle.x> 1 && posActuelle.x<56)&&( posActuelle.y>1 && posActuelle.y<30))
            {
             //cout<<"ennemi indice "<<e<<"   se deplace"<<endl;
                tabEnnemi.at(e).deplacer();
                       
            }
            
        }


        /// enboucle est une copie l'enemi actuel 
        //deplacerEnnemiBool=true;
        bool attaqueFerme=false;
        
        if(TabFerme.size()>0){
             
            indiceMinDistance=0;
            ferme1=TabFerme.at(ferme);
            posBati=ferme1.get_position();
            distanceMinimale=posEnne.distance(posBati);
            distanceActuelle=posEnne.distance(posBati);

            for(ferme=0;ferme<TabFerme.size();ferme++)
            {
                ferme1=TabFerme.at(ferme);
                posBati=ferme1.get_position();
                distanceActuelle=posEnne.distance(posBati);//tabEnnemi.po

                if(distanceActuelle<10.f)  //if(distanceActuelle<2.f)
                {

                    if(distanceActuelle<distanceMinimale)
                    {
                        distanceMinimale=distanceActuelle;
                        indiceMinDistance=ferme;
                        //cout<<indiceMinDistance;
                        if(distanceMinimale<1.2) //ennemi est assez proche pour attaquer le batiment
                        {
                            attaqueFerme=true;
                            indiceBatdegat=ferme;
                        }

                    }
                }   
            }

                if(attaqueFerme)
                        {
                            TabFerme.at(indiceBatdegat).degat(enboucle.get_degat());
                                //   faire des degats dans la ferme la plus proche

                        }

        }

    cout<<endl;
    }

}

void Jeu::enleveEntDestruites(){

    cout<<"eneeve det"<<endl; 
    long unsigned int bat,e,ferme;

    bat=tabBatDef.size();
    
    if(tabBatDef.size()>0){
        cout<<" size "<<tabBatDef.size()<<"  taille tab  ";
    for(bat=tabBatDef.size();bat>0;bat--)
        { 
            
                cout<<"Batiment indice"<< bat-1 <<" "; 
                if (tabBatDef.at(bat-1).getDetruit()==true ||  tabBatDef.at(bat-1).getPointsDeVie()<=0 )
                {
                tabBatDef.erase( tabBatDef.begin() + bat-1);
                    cout<<"BATIMENT "<<bat-1<< " EFFACEE"<<endl; 
                    //usleep(1000000);          
                }

    

        }
    }
  /* if(TabFerme.size()>0)
    {
        for(ferme=TabFerme.size()-1;ferme>=0;ferme--)
        {
            if (TabFerme.at(ferme).est_vivant()==false)  //si la ferme n'est plus vivante
            {
                TabFerme.erase(TabFerme.begin() + ferme);
            }
        }
    }

    if(tabEnnemi.size()>0)
    {
        for(e=tabEnnemi.size()-1;e>=0;e--)
        {
            if (tabEnnemi.at(e).get_statut()==false)  //si l'ennemi est eliminé
            {
                tabEnnemi.erase(tabEnnemi.begin()+e);
            }
        }
    }

    
    */
    

}
