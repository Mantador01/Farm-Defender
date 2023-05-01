    

    #ifndef JEU_H
    #define JEU_H

    #include "BatimentDefense.h"
    //#include "JeuModeTexte.h"
    #include "Ennemi.h"
    #include "StockageRessources.h"
    #include "Ferme.h"
    #include "BaseCentrale.h"
    #include <iostream>
    #include <vector>

    

    

    class Jeu{
        public:
        
        StockageRessources stockage;
        
        vector<Ennemi> tabEnnemi;
        
        vector<BatimentDefense> tabBatDef;
         
        vector<Ferme> TabFerme;
        
        float jeu_largeur, jeu_hauteur;

        
        void baseCentrale_proche_ennemi(Ennemi & enboucle, float & distance,Vect2 & cible );
        
        
        void bat_proche_ennemi(Ennemi & enboucle, bool & initBat,float & distanceMinimale,Vect2 & cible,long unsigned int & indiceMinDistance );
        
        
        void ferme_proche_ennemi(Ennemi & enboucle, bool & initFerme,float & distanceMinimale,Vect2 & cible, long unsigned int & indiceMinDistance);
        
        void deplacerEnnemis();

        
        void enleveEntDetruites();

        
        void ajouteTempsMortEnnemis(float tempsMort);

        
        Jeu();

        
        ~Jeu();


        
        void placerEnnemis(Type_ennemi type_en,int effectif);

        
        void ennemi_vivant_proche_bat(BatimentDefense batiment, bool & initEnne,long unsigned int & indiceMinDistance );
        

        
        void faireDegatBat();

        
        void BCproduction(bool est_vivant);

        
        void BCdegat(int degat);

        
        bool BCest_vivant();
        
        char BCm_carac;
        
        int BCm_size;
        
        float BCfloatdeg;

        
        Vect2 BCpos;
        
        void BCsetPos (float x, float y);
        
        
        Vect2 BCgetPos();

        
        void declancherVague(int num_vague);

        
        void BCAttaque();



    private:

        
        int BCm_pointsDeVie;

    
    };

    #endif







