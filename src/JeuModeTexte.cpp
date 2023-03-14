#include "JeuModeTexte.h"
#include "BatimentDefense.h"
#include "Jeu.h"
#include <iostream>

JeuModeTexte::JeuModeTexte(float largeur, float hauteur) : m_largeur(largeur), m_hauteur(hauteur) {
    m_carte = new char*[int(m_hauteur)];
    for (int i = 0; i < int(m_hauteur); i++) {
        m_carte[i] = new char[int(m_largeur)];
    }

    for (int i = 0; i < int(m_hauteur); i++) {
        for (int j = 0; j < int(m_largeur); j++) {
            if (i == 0 || j == 0 || i == int(m_hauteur)-1 || j == int(m_largeur)-1) {
                m_carte[i][j] = '+';
            } else {
                m_carte[i][j] = '.';
            }
        }
    }

    for (int i = (int(m_hauteur)/2)-2; i<=(int(m_hauteur)/2)+1; i++){
        for (int j = 0; j<int(m_largeur); j=j+(int(m_largeur)-1)){
            m_carte[i][j] = '#';
        }
    }

    for (int i = (int(m_hauteur)/2)-1;i <= int(m_hauteur)/2 ; i++){
        for (int j = 0;j<=int((m_largeur)/2)-2;j++){
            m_carte[i][j] = '>';
        }
        for (int j = (int(m_largeur)/2)+1;j<=int(m_largeur)-1;j++){
            m_carte[i][j] = '<';
        }
    }

    m_carte[int(m_hauteur)-1][(int(m_largeur)/2)-2] = '#';
    m_carte[int(m_hauteur)-1][(int(m_largeur)/2)+1] = '#';
    for (int i = int(m_hauteur)-1; i >= (int(m_hauteur)/2)+1; i--){
        for (int j = (int(m_largeur)/2)-1;j<=int(m_largeur)/2;j++){
            m_carte[i][j] = '^';
        }
    }

}

void JeuModeTexte::affObj(Vect2 post, int size, char car){
    bool condition_verifiee = true;
    if (size == 1) {
        if (m_carte[int(post.y)][int(post.x)] == '.') {
            m_carte[int(post.y)][int(post.x)] = car;
        }
    }
    else if(size == 2){
        if (m_carte[int(post.y)][int(post.x)] == '.' && m_carte[int(post.y)][int(post.x+1)] == '.'){
            m_carte[int(post.y)][int(post.x)] = car;
            m_carte[int(post.y)][int(post.x+1)] = car;
        }
    } 
    else {
        for (int i = int(post.y); i < int(post.y) + (size/2); i++) {
            for (int j = int(post.x); j < int(post.x) + (size/2); j++) {
                if (m_carte[i][j] != '.') {
                    condition_verifiee = false;
                    break;
                }
            }
            if (!condition_verifiee) {
                break;
            }

            if (i == int(post.y) + (size/2)-1 && int(post.x) + (size/2)-1 && condition_verifiee) {
                for (int i = int(post.y); i < int(post.y) + (size/2); i++) {
                    for (int j = int(post.x); j < int(post.x) + (size/2); j++) {
                        m_carte[i][j] = car;
                    }
                }
            }
        }
    }    
} 

JeuModeTexte::~JeuModeTexte() {
    for (int i = 0; i < m_hauteur; i++) {
        delete[] m_carte[i];
    }
    delete[] m_carte;
}

int JeuModeTexte::getLargeur() const {
    return m_largeur;
}

int JeuModeTexte::getHauteur() const {
    return m_hauteur;
}

void JeuModeTexte::afficher() const {
    for (int i = 0; i < m_hauteur; i++) {
        for (int j = 0; j < m_largeur; j++) {
            std::cout << m_carte[i][j];
        }
        std::cout << std::endl;
    }
}

int main(){

    Jeu jeuUnique;
    JeuModeTexte map(40,20);

    BatimentDefense bat1(TypeBatiment::Tourelle);
    BatimentDefense bat2(TypeBatiment::Canon);  

    jeuUnique.tabBatDef.push_back(bat1);
    jeuUnique.tabBatDef.push_back(bat2); 

    jeuUnique.tabBatDef.at(0).setPosition(1,1);
    jeuUnique.tabBatDef.at(1).setPosition(4,4);
    
    for (unsigned int i = 0; i<jeuUnique.tabBatDef.size();i++){
        switch (jeuUnique.tabBatDef.at(i).getType()){
            case TypeBatiment::Tourelle:
                jeuUnique.tabBatDef.at(i).setSize(4);
                jeuUnique.tabBatDef.at(i).setCarac('T');
                break;
            case TypeBatiment::Canon:
                jeuUnique.tabBatDef.at(i).setSize(2);
                jeuUnique.tabBatDef.at(i).setCarac('C'); 
                break;            
        }
        map.affObj(jeuUnique.tabBatDef.at(i).getPosition(),jeuUnique.tabBatDef.at(i).getSize(),jeuUnique.tabBatDef.at(i).getCarac());
    }

    map.afficher();

    return 0;
}
