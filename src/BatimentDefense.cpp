#include "BatimentDefense.h"
#include "Vect2.h"
#include <iostream>
using namespace std;

BatimentDefense::BatimentDefense(){
    BatimentDefense (TypeBatiment::Tourelle);
}

BatimentDefense::~BatimentDefense(){

}

BatimentDefense::BatimentDefense(TypeBatiment type){
    m_type = type;
    switch (type){
        case TypeBatiment::Tourelle:
            this->augmenterNiveau(100,1,0.1,1);
            break;
        case TypeBatiment::Canon:
            this->augmenterNiveau(100,1,0.1,1);
            break;
    }
}

TypeBatiment BatimentDefense::getType() const{
    return m_type;
}

int BatimentDefense::getNiveau() const{
    return m_niveau;
}

int BatimentDefense::getPointsDeVie () const{
    return m_pointsDeVie;
}

int BatimentDefense::getDegats () const{
    return m_degats;
}

float BatimentDefense::getVitesseAttauqe () const{
    return m_vitesse;
}

float BatimentDefense::getRayonAttaque () const{
    return m_rayonAttaque;
}

Vect2 BatimentDefense::getPosition () const{
    return m_position;
}

int BatimentDefense::getSize () const{
    return m_size;
}
char BatimentDefense::getCarac () const{
    return m_carac;
}

void BatimentDefense::setPosition (int x, int y){
    m_position.x = x;
    m_position.y = y; 
}

void BatimentDefense::setSize(int s){
    m_size = s;
}

void BatimentDefense::setCarac(char c){
    m_carac = c;
}

void BatimentDefense::setDetruit (bool estDetruit){
    this->m_estDetruit = estDetruit;
}

void BatimentDefense::upgrade(){
        
    switch (this->m_type){
        case TypeBatiment::Tourelle:
            switch(this->getNiveau()){
                case 0:
                this->augmenterNiveau(100,1,0.1,1);
                break;
                case 1:
                this->augmenterNiveau(100,2,0.2,2);
                break;
                case 2:
                this->augmenterNiveau(100,3,0.3,3);
                break;
            }
        break;
        case TypeBatiment::Canon:
            switch(this->getNiveau()){
                case 0:
                this->augmenterNiveau(100,1,0.1,1);
                break;
                case 1:
                this->augmenterNiveau(100,2,0.2,2);
                break;
                case 2:
                this->augmenterNiveau(100,3,0.3,3);
                break;
            }
        break;
    }
}

void BatimentDefense::augmenterNiveau(int pointsDeVie, int degats, float vitesseAttaque, float rayonAttaque){
    this->m_pointsDeVie = pointsDeVie;
    this->m_degats = degats;
    this->m_vitesse = vitesseAttaque;
    this->m_rayonAttaque = rayonAttaque; 
}
