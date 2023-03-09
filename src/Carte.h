    /**
    @brief Description brève du fichier Carte.h
    Description détaillée du fichier Carte.h
    @author P2111020/P2018147/P2105542
    @file Carte.h
    @version 1.0
    @date 07/03/2023
    */

    #ifndef CARTE_H
    #define CARTE_H

    #include <iostream>
    #include <vector>

    class Carte {
    private:
        int m_largeur, m_hauteur;
        char** m_carte;
    public:
        Carte(int largeur, int hauteur);
        ~Carte();
        void afficher() const;
        int getHauteur() const;
        int getLargeur() const;
    };

    #endif