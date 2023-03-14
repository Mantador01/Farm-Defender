#include "JeuModeTexte.h"
#include "BatimentDefense.h"
#include "Jeu.h"
#include <iostream>
#include "StockageRessources.h"
#include "Ferme.h"
#include <ctime> // pour la fonction time()
#include <unistd.h>
#include "BaseCentrale.h"

using namespace std;

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
        if (m_carte[int(post.y)][int(post.x)] != '.') {
            m_carte[int(post.y)][int(post.x)] = car;
        }
    } else {
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

void termClear()  // efface le terminal
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(){

    time_t startTime = time(NULL); // temps de départ
    time_t currentTime;
    int elapsedSeconds;
    int hours, minutes, seconds;

    Vect2 pos;
    pos.x = 0;
    pos.y = 0;

    
    // Création d'un stockage de ressources
    StockageRessources stockage;

    // Création de 3 fermes
    Ferme ferme1(stockage);
    Ferme ferme2(stockage);
    Ferme ferme3(stockage);

    
    /*ferme1.creation(pos);
    ferme2.creation(pos);
    ferme3.creation(pos);*/
    
    BaseCentrale BC(stockage);

        // Affichage des ressources initiales
    cout << "Ressources initiales :" << endl;
    stockage.afficherRessources();

    BatimentDefense bat;
    bat.setPosition(19,9);
    bat.setSize(4);
    bat.setCarac('B');
    
    JeuModeTexte map(40,20);
    /*map.affObj(bat.getPosition(),bat.getSize(),bat.getCarac());
    map.afficher();*/


    Jeu jeuUnique;
    BatimentDefense bat1,bataj;

    jeuUnique.tabBatDef.push_back(bat1);
    bataj=jeuUnique.tabBatDef.at(0);
    std::cout << bataj.getSize () <<" size bat";std::cout << std::endl;



    
    // Démarrage de la production des fermes

    while(seconds!=20) {
        termClear();

        // obtenir le temps actuel et calculer le temps écoulé depuis le début
        currentTime = time(NULL);
        elapsedSeconds = difftime(currentTime, startTime);

        // convertir en heures, minutes et secondes
        hours = elapsedSeconds / 3600;
        minutes = (elapsedSeconds % 3600) / 60;
        seconds = elapsedSeconds % 60;

        map.affObj(bat.getPosition(),bat.getSize(),bat.getCarac());
        map.afficher();

        // afficher le timer
        cout << "Temps écoulé : ";
        cout << hours << " heures, ";
        cout << minutes << " minutes et ";
        cout << seconds << " secondes." << endl;

        
        ferme1.degat(1);
        ferme2.degat(2);
        ferme3.degat(3);

        BC.degat(50);

        ferme1.production(ferme1.est_vivant());
        ferme2.production(ferme2.est_vivant());
        ferme3.production(ferme3.est_vivant());

        BC.production(BC.est_vivant());
        
        cout << "Ressources actuel :" << endl;
        stockage.afficherRessources();

        sleep(1);
    }

    // Affichage des ressources finales
    cout << "Ressources finales :" << endl;
    stockage.afficherRessources();


    return 0;
}
