    /**
    @brief Description brève du fichier JeuModeTexte.h
    Description détaillée du fichier JeuModeTexte.h
    @author Ahmed/Alexandre/Sara
    @file JeuModeTexte.h
    @version 1.0
    @date 01/05/2023
    */   

    #ifndef JEUMODETEXTE_H
    #define JEUMODETEXTE_H

    #include "Vect2.h"
    #include "Jeu.h"

    /**
    @brief Classe représentant un jeu en mode texte
    */
    class JeuModeTexte {
    private:
    float m_largeur;    //!< \brief Largeur de la carte de jeu
    float m_hauteur;    //!< \brief Hauteur de la carte de jeu
    char** m_carte;     //!< \brief Tableau 2D représentant la carte de jeu
    char* win;          //!< \brief Tableau 1D stockant le contenu de la fenêtre mais accessible en 2D

public:
    /**
    @brief Constructeur de la classe JeuModeTexte
    Initialise les dimensions de la carte de jeu avec les valeurs passées en paramètres et alloue la mémoire pour le tableau 2D représentant la carte
    @param largeur Largeur de la carte de jeu
    @param hauteur Hauteur de la carte de jeu
    */
    JeuModeTexte(float largeur, float hauteur);

    /**
    @brief Affiche un objet sur la carte de jeu
    @param pos Position de l'objet sur la carte de jeu
    @param size Taille de l'objet à afficher
    @param car Caractère représentant l'objet à afficher
    */
    void affObj(Vect2 pos, int size, char car);

    /**
    @brief Efface un objet de la carte de jeu
    @param pos Position de l'objet sur la carte de jeu
    @param size Taille de l'objet à effacer
    */
    void effacerObj(Vect2 pos, int size);

    /**
    @brief Initialise le tableau 2D représentant la carte de jeu avec des caractères vides
    */
    void initTab();

    /**
    @brief Destructeur de la classe JeuModeTexte
    Libère la mémoire allouée pour le tableau 2D représentant la carte de jeu et le tableau 1D stockant le contenu de la fenêtre
    */
    ~JeuModeTexte();

    /**
    @brief Affiche la carte de jeu
    */
    void afficher() const;

    /**
    @brief Retourne la hauteur de la carte de jeu
    @return Hauteur de la carte de jeu
    */
    int getHauteur() const;

    /**
    @brief Retourne la largeur de la carte de jeu
    @return Largeur de la carte de jeu
    */
    int getLargeur() const;

    /**
    @brief Boucle principale du jeu en mode texte
    @param j Instance du jeu à lancer en mode texte
    */
    void BoucleJeu(Jeu &j);
};

#endif