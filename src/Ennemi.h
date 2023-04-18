/**
@brief Description brève du fichier Ennemi.h
Description détaillée du fichier Ennemi.h
@author P2105542
@file Ennemi.h
@version 1.0
@date 2023/03/07
*/

#ifndef ENNEMI_H
#define ENNEMI_H

#include "Vect2.h"
#include <stdlib.h>
/**
@brief type ennumere pour identifier le type d'ennemi
*/
enum Type_ennemi
{
    zombi,
    z_infectieu,
    z_berserker,
    pillard
};

/*const float XPntGenZSpw1 = 20 ;
const float YPntGenZSpw1 = 20 ;

const float XPntGenZSpw2 = 10 ;
const float YPntGenZSpw2 = 10 ;

const float XPntGenZSpw3 = 15 ;
const float YPntGenZSpw3 = 15 ;*/


/**
@brief Classe représentant un ennemi
*/

class Ennemi
{
private:

/**
    * @brief Statut de l ennemi 0 eliminé 1 vivant
    * 
    */

    bool statut;
    /**
    * @brief Identification du type d’ennemi avec un type ennum
    * 
    */

    Type_ennemi type_en;
    /**
    * @brief Points de sante restaurant a l’ennemi
    * 
    */

    int sante;
    /**
    * @brief Degat fait par l’ennemi
    * 
    */

    int degat;
    /**
    * @brief Facteur de vitesse
    * 
    */

    float vitesse;
    /**
    * @brief Vecteur de direction du mouvement
    * 
    */

    Vect2 direction;
    /**
    * @brief Vecteur de position de l’ennemi
    * 
    */

    Vect2 position;
     /**
    * @brief combien de temps l'ennemi a ete eliminé / temps ou il est mort
    * 
    */
    float temps_mort;


public:
    /**
    @brief Accesseur pour champ x de position d'ennemi
    @return valeur de type float
    */
    float splitX();
    /**
    @brief Accesseur pour champ y de position d'ennemi
    @return valeur de type float
    */
    float splitY();
	
    /**
    @brief Constructeur par défaut: Initialise l’ennemi comme un zombi
   */
    Ennemi();
    /**
    @brief Destructeur de la classe Ennemi
    */
    ~Ennemi();

    /**
    @brief Constructeur Ennemi avec paramètres
    Initialise les champs avec les valeurs passées en paramètres
    @param nomé Type_ennemi de type :typeEnnemi
    */
    Ennemi(Type_ennemi typeEnnemi);

    /**
    @brief deplace un elemi selon sa position,direction et vitesse
    */
    void deplacer();
    

    /**
    @brief enleverVide eleve points_enleves des points de sante et si ce champ et met a jour le statut
    @param points_enleves int points a enlever de l ennemi
    */
    void enleverSante(int points_enleves);
    /**
    @brief Accesseur pour degat
    @return valeur du degat cause par ennemi
    */
    int get_degat();
    /**
    @brief Accesseur pour type d'ennemi
    @return valeur de type type_ennemi
    */
    Type_ennemi getType()const;

    /**
    @brief Affiche les champs d'ennemi
    */
   void afficher();
    
    //void agir(); // gestion du déplacement, dégâts, sante …

    /**
    @brief mutateur pour la direction de Ennemi 
    @param vect2 la nouvelle direction
    */
   void set_direction(Vect2 dir);
    /**
    @brief Accesseur pour position d'ennemi
    @return valeur de type Vect2
    */
   Vect2 get_position();

   void set_pos(Vect2 posi);
       /**
    @brief 
    */
   int get_sante ();
    /**
    @brief Accesseur pour statut 0 eliminé 1 vivant
    @return valeur du statut
    */
   bool get_statut();

   /**
    @brief Accesseur pour temps mort d'un ennemi
    @return valeur detemps mort
    */
   float get_temps_mort();

   /**
   @brief mutateur pour temps mort d'un ennemi ajoute tempsMort a temps mort d'un ennemi
    @param float tempsMort a ajouter
    */
   void add_temps_mort(float tempsMort);

};


#endif // ENNEMI_H
