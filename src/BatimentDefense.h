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

    enum TypeBatiment {
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
        ~BatimentDefense();


        private:

        TypeBatiment type;
        Vect2 m_position;
        bool m_estDetruit;
        float m_vitesse;
        int m_degats;
        int m_pointsDeVie;
        int m_niveau;
        float m_rayonAttaque;

    };
    #endif