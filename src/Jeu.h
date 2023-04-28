    /**
    @brief Description brève du fichier Jeu.h
    Description détaillée du fichier Jeu.h
    @author P2111020/P2018147/P2105542
    @file Jeu.h
    @version 1.0
    @date 14/03/2023
    */

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

    

    /**
    @brief Classe représentant le noyau du jeu (entités et autres champs)
    */

    class Jeu{
        public:
        /**
        * @brief stockage des ressources  gold bois pierre nourriture
        */
        StockageRessources stockage;
        /**
        * @brief tablequ dinamique qui contient tous les ennemis du jeu tant que les ennemis ne soient pas elimines
        */
        vector<Ennemi> tabEnnemi;
        /**
        * @brief tablequ dinamique qui contient tous les Batiment de Defense du jeu tant que les ennemis ne soient pas elimines
        */
        vector<BatimentDefense> tabBatDef;
         /**
        * @brief tablequ dinamique qui contient tous les Fermes du jeu tant que les ennemis ne soient pas elimines
        */
        vector<Ferme> TabFerme;
        /**
         @brief dimention du terrain de jeu 
        */
        float jeu_largeur, jeu_hauteur;

        /**
         @brief calcule la distance entre la base centrale et l'ennemi 
         @param enboucle ennemi, float distance, vect2 cible position base centrale
        */
        void baseCentrale_proche_ennemi(Ennemi & enboucle, float & distance,Vect2 & cible );
        
        /**
         @brief si un batiment vivant est proche, trouve le batiment le plus proche, son indice dans le tableau et ca position
         @param enboucle ennemi, bool initBat true si il y aun batiment vivant, float distanceMinimale  vect2 cible, indiceMinDistance indice dans tab
        */
        void bat_proche_ennemi(Ennemi & enboucle, bool & initBat,float & distanceMinimale,Vect2 & cible,long unsigned int & indiceMinDistance );
        
        /**
         @brief si un batiment vivant est proche, trouve le batiment le plus proche, son indice dans le tableau et ca position
         @param enboucle ennemi, bool initferme true si il y aun batiment vivant, float distanceMinimale  vect2 cible , indiceMinDistance indice dans tab
        */
        void ferme_proche_ennemi(Ennemi & enboucle, bool & initFerme,float & distanceMinimale,Vect2 & cible, long unsigned int & indiceMinDistance);
        /**
        @brief deplacerEnnemis deplace tous les ennemis du jeu en prenant en compte les positionnemet des batiments
        */
        void deplacerEnnemis();

        /**
         @brief enleve les entités qui ont ete éliminés  
        */
        void enleveEntDetruites();

        /**
        @brief ajoute un temps mort a tous les ennemis morts
        @param float tempsMort a ajouter
        */
        void ajouteTempsMortEnnemis(float tempsMort);

        /**
         @brief Constructeur de Jeu 
        */
        Jeu();

        /**
         @brief Destructeur de Jeu
        */
        ~Jeu();


        /**
         @brief place un N ennemis de type type_en dans le tableau qui contient tous les ennemis
         @param type_en type des ennemis, de type Type_ennemi ,int effectif le nombre d'ennemis
        */
        void placerEnnemis(Type_ennemi type_en,int effectif);

        /**
        @brief si il y a des ennemis vivants proches, trouve l'indice du plus proche, son indice dans le tableau et ca position
        @param BatimentDefense batiment, bool initEnne true si il y a un ennemi vivant dans le rayon d'ataque du batiment, long unsigned int & indiceMinDistance
        */
        void ennemi_vivant_proche_bat(BatimentDefense batiment, bool & initEnne,long unsigned int & indiceMinDistance );
        

        /**
        @brief effectue le degat infligé par chacun des batiments vivants sur l'ennemi (non eliminé) le plus proche
        */
        void faireDegatBat();

        /**
        @brief Fonction production qui incrémente les ressources de 10 a chaques appels de cette fonction seulement si la BaseCentrale est vivante.
        @param Booléen : est_vivant renvoie true si la ferme est toujour vivante(vie>0) false sinon.
        */
        void BCproduction(bool est_vivant);

        /**
        @brief Fonction degat qui permet de soustraire les dégats passer en paramètre et la vie de la BaseCentrale.
        @param Entier : degat les dégats a soustraire a la vie.
        */
        void BCdegat(int degat);

        /**
        @brief Fonction qui renvoie true si la BaseCentrale est vivante et donc le jeu continue.
        */
        bool BCest_vivant();

        int BCm_carac;

        int BCm_size;

        /**
        @param Vect2 : pos la position de la BaseCentrale.
        */
        Vect2 BCpos;

        void BCsetPos (int x, int y);
        
        /**
        @return Vect2 : returne pos la position de la BaseCentrale.
        */
        Vect2 BCgetPos();

        /**
        @brief Fonction qui place des ennemis pour faire la vague d'attaque
        @param Entier : le numero de la vague
        */
        void declancherVague(int num_vague);



    private:

        /**
        @param Entier : m_pointsDeVie la vie de la BaseCentrale.
        */
        int BCm_pointsDeVie;

    
    };

    #endif







