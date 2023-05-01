/**
@brief Description brève du fichier Ferme.h
Description détaillée du fichier Ferme.h
@author Ahmed/Alexandre/Sara
@file Image.h
@version 1.0
@date 01/05/2023
*/

#ifndef FERME_H
#define FERME_H

#include "StockageRessources.h"
#include "Vect2.h"

using namespace std;




/**
@brief Classe représentant une ferme
*/
class Ferme {
public:

/**
@brief Constructeur de la classe Ferme
@param stockage Stockage de ressources associé à la ferme
*/
Ferme(StockageRessources& stockage);

/**
@brief Produit des ressources en fonction du statut de vie de la ferme
@param est_vivant Statut de vie de la ferme
*/
void production(bool est_vivant);

/**
@brief Enlève des points de vie à la ferme
@param degat Nombre de points de vie à enlever
*/
void degat(int degat);

/**
@brief Obtient le statut de vie de la ferme
@return true si la ferme est en vie, false sinon
*/
bool est_vivant();

/**
@brief Crée une nouvelle ferme à la position spécifiée
@param posi Position de la nouvelle ferme
*/
void creation(Vect2 posi);

StockageRessources* m_stockage; /**< Stockage de ressources associé à la ferme */

/**
@brief Obtient la position de la ferme
@return Position de la ferme
*/
Vect2 get_position();


private:

int m_pointsDeVie; /**< Nombre de points de vie de la ferme */
Vect2 pos; /**< Position de la ferme */


};

#endif // FERME_H