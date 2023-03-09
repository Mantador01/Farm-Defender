    /**
    @brief Description brève du fichier JeuModeTexte.h
    Description détaillée du fichier JeuModeTexte.h
    @author P2111020/P2018147/P2105542
    @file JeuModeTexte.h
    @version 1.0
    @date 09/03/2023
    */

    #ifndef JEUMODETEXTE_H
    #define JEUMODETEXTE_H

    class JeuModeTexte {
    private:
        int m_largeur, m_hauteur;
        char** m_carte;
    public:
        JeuModeTexte(int largeur, int hauteur);
        ~JeuModeTexte();
        void afficher() const;
        int getHauteur() const;
        int getLargeur() const;
    };

    #endif