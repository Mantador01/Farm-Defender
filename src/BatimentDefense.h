    /**
    @brief Description brève du fichier BatimentDefense.h
    Description détaillée du fichier BatimentDefense.h
    @author P2111020/P2018147/P2105542
    @file BatimentDefense.h
    @version 1.0
    @date 07/03/2023
    */

    #ifndef BATIMENTDEFENSE_H
    #define BATIMENTDEFENSE_H

    #include "Vect2.h"
    #include <iostream>

    enum class TypeBatiment {
        Tourelle,
        Canon
    };

    /**
    @brief Classe représentant les propriétés d'un batiment de défense
    */
    class BatimentDefense
    {
        public:


        BatimentDefense();
        BatimentDefense(TypeBatiment type);
        ~BatimentDefense();
        TypeBatiment getType() const;
        int getNiveau() const;
        int getPointsDeVie () const;
        int getDegats () const;
        float getVitesseAttauqe () const;
        float getRayonAttaque () const;
        Vect2 getPosition () const;
        int getSize () const;
        char getCarac () const;
        void setPosition (int x, int y);
        void setSize(int s);
        void setCarac(char c);
        void setDetruit (bool estDetruit);
        void upgrade();
        void augmenterNiveau(int pointsDeVie, int degats, float vitesseAttaque, float rayonAttaque);
        void afficher();

        void enleverPointsVie(int points_enleves);
        bool getDetruit ();

        float splitX();
        float splitY();

        float getX () const;
        float getY () const;



        private:

        int m_size;
        char m_carac;
        TypeBatiment m_type;
        Vect2 m_position;
        bool m_estDetruit;
        float m_vitesse;
        int m_degats;
        int m_pointsDeVie;
        int m_niveau;
        float m_rayonAttaque;
        

    };
    #endif
