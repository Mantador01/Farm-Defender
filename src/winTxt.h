    /**
    @brief Description brève du fichier winTxt.h
    Description détaillée du fichier winTxt.h
    @author Ahmed/Alexandre/Sara
    @file winTxt.h
    @version 1.0
    @date 01/05/2023
    */ 

#ifndef WINTXT_H
#define WINTXT_H



/**
@brief Classe représentant une fenêtre de texte utilisant la console
*/
class WinTXT
{
private:

int dimx; /**< Largeur de la fenêtre */ 
int dimy; /**< Hauteur de la fenêtre */
char* win; /**< Tableau de pixels représentant la fenêtre */


public:

/**
@brief Constructeur avec paramètres
Initialise les dimensions de la fenêtre avec les valeurs passées en paramètres et alloue la mémoire pour le tableau de pixels
@param dx Largeur de la fenêtre
@param dy Hauteur de la fenêtre
*/
WinTXT (int dx, int dy);

/**
@brief Efface le contenu de la fenêtre
@param c Caractère utilisé pour remplir la fenêtre (espace par défaut)
*/
void clear (char c=' ');

/**
@brief Affiche un caractère dans la fenêtre à la position spécifiée
@param x Coordonnée en abscisse du caractère
@param y Coordonnée en ordonnée du caractère
@param c Caractère à afficher
*/
void print (int x, int y, char c);

/**
@brief Affiche une chaîne de caractères dans la fenêtre à la position spécifiée
@param x Coordonnée en abscisse de la chaîne
@param y Coordonnée en ordonnée de la chaîne
@param c Chaîne de caractères à afficher
*/
void print (int x, int y, char* c);

/**
@brief Affiche le contenu de la fenêtre dans la console à partir de la position spécifiée
@param x Position en abscisse de la fenêtre à partir de laquelle l'affichage commence (0 par défaut)
@param y Position en ordonnée de la fenêtre à partir de laquelle l'affichage commence (0 par défaut)
*/
void draw (int x=0, int y=0);

/**
@brief Attend qu'une touche soit pressée et retourne le caractère correspondant
*/
void pause();

/**
@brief Attend qu'une touche soit pressée et retourne le caractère correspondant (équivalent à pause())
@return Caractère pressé
*/
char getCh();

};

/**
@brief Efface le contenu de la console
*/
void termClear ();

#endif