

#ifndef ENNEMI_H
#define ENNEMI_H

#include "Vect2.h"
#include <stdlib.h>

enum Type_ennemi
{
    zombi,
    z_infectieu,
    z_berserker,
    pillard
};






class Ennemi
{
private:



    bool statut;
    

    Type_ennemi type_en;
    

    int sante;
    

    int degat;
    

    float vitesse;
    

    Vect2 direction;
    

    Vect2 position;
     
    float temps_mort;


public:
    
    float splitX();
    
    float splitY();
	
    
    Ennemi();
    
    ~Ennemi();

    
    Ennemi(Type_ennemi typeEnnemi);

    
    void deplacer();
    

    
    void enleverSante(int points_enleves);
    
    int get_degat();
    
    Type_ennemi getType()const;

    
   void afficher();
    
    
    
   void set_direction(Vect2 dir);
    
   Vect2 get_position();

   void set_pos(Vect2 posi);
       
   int get_sante ();
    
   bool get_statut();

   
   float get_temps_mort();

   
   void add_temps_mort(float tempsMort);

};


#endif 