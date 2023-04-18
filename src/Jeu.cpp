#include "Jeu.h"
#include <unistd.h> //sleep?
#include <iostream>
#include <vector>
using namespace std;

void Jeu::BCproduction(bool est_vivant)
{
    if(est_vivant){
    stockage.ajouterRessource("gold", 10);
    stockage.ajouterRessource("pierre", 10);
    stockage.ajouterRessource("bois", 10);
    stockage.ajouterRessource("nourriture", 10);}
}

void Jeu::BCdegat(int degat)
{
    BCm_pointsDeVie -= degat;
}

bool Jeu::BCest_vivant()
{
    if(BCm_pointsDeVie<=0){
        return false;
    }else{return true;}
}

void Jeu::BCsetPos (int x, int y){
    BCpos.x = x;
    BCpos.y = y;
}

Vect2 Jeu::BCgetPos(){
    return BCpos;
}




Jeu::Jeu(){

    jeu_largeur=40; jeu_hauteur=20;
    BCm_carac = 'O';

    BatimentDefense bat1(TypeBatiment::Tourelle);
    BatimentDefense bat2(TypeBatiment::Canon);  

    BatimentDefense bat3(TypeBatiment::Canon);  
    bat3.setPosition (10,2);

    tabBatDef.push_back(bat1);
    tabBatDef.push_back(bat2);
    tabBatDef.push_back(bat3);

  //  tabBatDef.at(0).setPosition(100,100);
   // tabBatDef.at(1).setPosition(750,200);
     tabBatDef.at(0).setPosition(5,5);
    tabBatDef.at(1).setPosition(7,7);

    Ennemi enm1(Type_ennemi::zombi);
    tabEnnemi.push_back(enm1);

    Vect2 pos1(15,17);

    Vect2 dire(1,0);

    tabEnnemi.at(0).set_pos(pos1);

    tabEnnemi.at(0).set_direction(dire);

    Ennemi zombiTest;

    Vect2 posZombi(12,17);
    zombiTest.set_pos(posZombi);
    Vect2 dire2(1,0);
    zombiTest.set_direction(dire2);
    tabEnnemi.push_back(zombiTest);
    
     Vect2 posZombi2(11,19);
    zombiTest.set_pos(posZombi2);
    tabEnnemi.push_back(zombiTest);


}

Jeu::~Jeu(){

}



void Jeu::placerEnnemis(Type_ennemi type_en,int effectif){
	Vect2 posZCentre(jeu_largeur/2,jeu_hauteur-5);
	Vect2 posZDroite(jeu_largeur,jeu_hauteur/2);
	Vect2 posZGauche(5,jeu_hauteur/2);
	Vect2 pos;
	int r;

	switch(type_en){
		
		case zombi:{
			for(int i=0;i<effectif;i++)
			{
				r=rand()%3;
				switch(r){
				case 0: {pos=posZCentre;
						break;}
				case 1: {pos=posZDroite;
						break;}
				case 2: pos=posZGauche;
						break;}
				Ennemi enm1(type_en);
				Vect2 posi(pos.x+((float)(rand()%21-10)),pos.y+((float)(rand()%21-10)));
				enm1.set_pos(posi);
				tabEnnemi.push_back(enm1);
				
			}
			break;
			}
		case z_infectieu:{
			for(int i=0;i<effectif;i++)
			{
				r=rand()%3;
				switch(r){
				case 0: {pos=posZCentre;
						break;}
				case 1: {pos=posZDroite;
						break;}
				case 2: pos=posZGauche;
						break;}
				Ennemi enm1(type_en);
				Vect2 posi(pos.x+((float)(rand()%21-10)),pos.y+((float)(rand()%21-10)));
				enm1.set_pos(posi);
				tabEnnemi.push_back(enm1);
				
			}
			break;
			}
		case pillard:{
			for(int i=0;i<effectif;i++)
			{
				r=rand()%3;
				switch(r){
				case 0: {pos=posZCentre;
						break;}
				case 1: {pos=posZDroite;
						break;}
				case 2: pos=posZGauche;
						break;}
				Ennemi enm1(type_en);
				Vect2 posi(pos.x+((float)(rand()%21-10)),pos.y+((float)(rand()%21-10)));
				enm1.set_pos(posi);
				tabEnnemi.push_back(enm1);
			}
			break;
			}
		case z_berserker:{
			for(int i=0;i<effectif;i++)
			{
				r=rand()%3;
				switch(r){
				case 0: {pos=posZCentre;
						break;}
				case 1: {pos=posZDroite;
						break;}
				case 2: pos=posZGauche;
						break;}
				Ennemi enm1(type_en);
				Vect2 posi(pos.x+((float)(rand()%21-10)),pos.y+((float)(rand()%21-10)));
				enm1.set_pos(posi);
				tabEnnemi.push_back(enm1);
				
			}
			break;
			}
		}
}


void Jeu::bat_proche_ennemi(Ennemi & enboucle, bool & initBat,float & distanceMinimale,Vect2 & cible,long unsigned int & indiceMinDistance ){
    initBat=false;
    float distanceActuelle;
    long unsigned int bat;

    if(tabBatDef.size()>0){
        BatimentDefense batiment;
        for(bat=0;bat<tabBatDef.size();bat++){ //parcours de tous les batiments
            batiment=tabBatDef.at(bat);
            if(batiment.getDetruit()==false){//est vivant
                distanceActuelle=enboucle.get_position().distance(batiment.getPosition());
                if(initBat==false){
                    initBat=true; indiceMinDistance=bat;
                    distanceMinimale=distanceActuelle;
                }else{
                    if(distanceActuelle<distanceMinimale){
                        distanceMinimale=distanceActuelle;
                        indiceMinDistance=bat;
                    }

                }
            }
        }
        cible=tabBatDef.at(indiceMinDistance).getPosition();
    }

}

void Jeu::ferme_proche_ennemi(Ennemi & enboucle, bool & initFerme,float & distanceMinimale,Vect2 & cible, long unsigned int & indiceMinDistance){
    initFerme=false;
    float distanceActuelle;
    long unsigned int ferme;

    StockageRessources stockage;
    Ferme fermeActuelle(stockage);
    Vect2 pos(0,0);
    fermeActuelle.creation(pos);



    if(TabFerme.size()>0){
        for(ferme=0;ferme<TabFerme.size();ferme++){ //parcours de tous les batiments
            fermeActuelle=TabFerme.at(ferme);
            if(fermeActuelle.est_vivant()==true){//est vivante
                Vect2 pos=enboucle.get_position();
                distanceActuelle=pos.distance(fermeActuelle.get_position());
                if(initFerme==false){
                    initFerme=true; indiceMinDistance=ferme;
                    distanceMinimale=distanceActuelle;
                }else{
                    if(distanceActuelle<distanceMinimale){
                        distanceMinimale=distanceActuelle;
                        indiceMinDistance=initFerme;
                    }

                }
            }
        }
        cible=TabFerme.at(indiceMinDistance).get_position();
    }

}

void Jeu::baseCentrale_proche_ennemi(Ennemi & enboucle, float & distance,Vect2 & cible ){
    //Vect2 baseCentre(jeu_largeur/2, jeu_hauteur/2);
    cible=BCpos;
    distance=enboucle.get_position().distance(cible);
}

void Jeu::deplacerEnnemis(){ 
    long unsigned int e,indiceMinDistBatDef,indiceMinDistFerme;
    bool initBat=false,initFerme=false,deplacerEnnemiBool;
    Vect2 cibleBatDef,cibleFerme,cibleBaseCentrale;
    Vect2 nouveauDepl,cibleGenerale;
    float distMinBatDef,distMinFerme,distBaseCentrale;
    float distMinGenerale;
    Ennemi enboucle;
    int aiguillageAttaque=0;  // 0 vers baseCentrale 1 vers Batiment at intBat 2 vers Ferme at indFerme
    Type_ennemi typeEnnemi;

    for(e=0;e<tabEnnemi.size();e++){

        if(tabEnnemi.at(e).get_statut()==true){ //si ennemi est vivant

            
            initBat=false;initFerme=false;
            deplacerEnnemiBool=true;

            enboucle=tabEnnemi.at(e);

            /////if enboucle de type zombi alors deplacement vers la base centrale

            typeEnnemi=enboucle.getType();

            if(typeEnnemi==zombi){
                baseCentrale_proche_ennemi(enboucle,distBaseCentrale,cibleBaseCentrale);
                if(distBaseCentrale<1.f){ //6.f
                    //BaseCentrale.degat(enboucle.get_degat());

                }else{
                    nouveauDepl=cibleBaseCentrale-enboucle.get_position();
                    nouveauDepl.normailiser();
                    tabEnnemi.at(e).set_direction(nouveauDepl);
                    tabEnnemi.at(e).deplacer();

                }

            }else{
                bat_proche_ennemi(enboucle,initBat,distMinBatDef,cibleBatDef,indiceMinDistBatDef);
                ferme_proche_ennemi(enboucle,initFerme,distMinFerme,cibleFerme,indiceMinDistFerme);
                baseCentrale_proche_ennemi(enboucle,distBaseCentrale,cibleBaseCentrale);

                distMinGenerale=distBaseCentrale;
                if(initBat==true){
                    if(distMinBatDef<distMinGenerale){
                    aiguillageAttaque=1;
                    distMinGenerale=distMinBatDef;
                }
                }
                if(initFerme==true){
                    if(distMinFerme<distMinGenerale){
                    aiguillageAttaque=2;
                    distMinGenerale=distMinFerme;
                }
                }
                

                if(distMinGenerale<6.f){
                    deplacerEnnemiBool=false;
                    switch(aiguillageAttaque)
                    {
                        case 0:
                            //BaseCentrale.degat(enboucle.get_degat());
                            break;
                        case 1:
                            tabBatDef.at(indiceMinDistBatDef).enleverPointsVie(enboucle.get_degat());
                            break;
                        case 2:
                            TabFerme.at(indiceMinDistFerme).degat(enboucle.get_degat());
                            break;

                    }
                }

                if(deplacerEnnemiBool==true){

                    switch(aiguillageAttaque)
                    {
                        case 0:
                            cibleGenerale=cibleBaseCentrale;
                            break;
                        case 1:
                            cibleGenerale=cibleBatDef;
                            break;
                        case 2:
                            cibleGenerale=cibleFerme;
                            break;

                    }
                    
                    //Pour normaliser le vecteur de deplacemetdistance_pour_normaliser;
                    nouveauDepl=cibleGenerale-enboucle.get_position();
                    nouveauDepl.normailiser();
                    tabEnnemi.at(e).set_direction(nouveauDepl);
                    tabEnnemi.at(e).deplacer();
                }

            }

        }   
            
    }

}



void Jeu::faireDegatBat(){
/*
    long unsigned int e,bat1;
    long unsigned int indiceMinDistance;
    long unsigned int indiceBatdegat;
    float distanceActuelle,distanceMinimale;

    bool ennemiProche,init=false;
    Ennemi enboucle;
    Vect2 posEnne,posBati;
    BatimentDefense bati;

    if(tabBatDef.size()>0){
        for(bat=0;bat<tabBatDef.size();bat++) //test proximité des ennemis par rappot a le batiment pour  les batiments vivants
        {  ennemiProche=false;
            if(tabBatDef.at(bat).getDetruit()!=true){
                bati=tabBatDef.at(bat);
                posBati=bat.getPosition();

                for(e=0;e<tabEnnemi.size();e++)
                {   enboucle=tabEnnemi.at(e);
                    distanceActuelle=enboucle.get_position().distance(posBati);
                    if(distanceActuelle<=bati.m_rayonAttaque)
                    {
                        ennemiProche=true;
                        if(init==false){distanceMinimale=distanceActuelle; indiceMinDistance=e;}
                        else{
                            if(distanceActuelle<distanceMinimale){
                                distanceMinimale=distanceActuelle;
                                indiceMinDistance=e;
                             }
                            }
                    }
                    //si assez proche alors on stoque son indice et n met ennemi proche vrai
                    //indiceMinDistance contien l'indice de l'ennemi le plus proche                 
                }

                if(ennemiProche==true){
                    tabEnnemi.at(indiceMinDistance).enleverSante(bati.getDegats());
                }
            }
            
           
        }  

    }
*/
            
}