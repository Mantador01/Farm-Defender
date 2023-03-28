#include "JeuModeTexte.h"
#include "BatimentDefense.h"
#include "Jeu.h"
#include <iostream>
#include "StockageRessources.h"
#include "Ferme.h"
#include <ctime> // pour la fonction time()
#include <unistd.h>
#include "BaseCentrale.h"
#include "winTxt.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cassert>
/*
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include <conio.h>
#include "winTxt.h"
*/

#if _WIN32
#include <windef.h>
#include <winbase.h>
#include <wincon.h>
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>


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
        if ((m_carte[int(post.y)][int(post.x)] == '.')||(m_carte[int(post.y)][int(post.x)] == 'Z') ||(m_carte[int(post.y)][int(post.x)] == '>') ||(m_carte[int(post.y)][int(post.x)] == '<') ){
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




void JeuModeTexte::effacerObj(Vect2 post, int size){
    bool condition_verifiee = true;
   char car='.';
    if (size == 1) {
        if ((m_carte[int(post.y)][int(post.x)] == '.')||(m_carte[int(post.y)][int(post.x)] == 'Z') ||(m_carte[int(post.y)][int(post.x)] == '>') ||(m_carte[int(post.y)][int(post.x)] == '<') ){
            m_carte[int(post.y)][int(post.x)] = car;
        }
    }
    else if(size == 2){
        //if (m_carte[int(post.y)][int(post.x)] == '.' && m_carte[int(post.y)][int(post.x+1)] == '.'){
            m_carte[int(post.y)][int(post.x)] = car;
            m_carte[int(post.y)][int(post.x+1)] = car;
        //}
    } 
    else {
        for (int i = int(post.y); i < int(post.y) + (size/2); i++) {
            for (int j = int(post.x); j < int(post.x) + (size/2); j++) {
                if (m_carte[i][j] != '.') {
                    condition_verifiee = true;    //false
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

/*
void termClear()  // efface le terminal
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
*/

void H(int h)
{
    if(h < 10){
        cout<<"0"<<h;
    }else{
    cout<<h;}
}

void M(int m)
{
    if(m < 10){
        cout<<"0"<<m;
    }else{
    cout<<m;}
}

void S(int s)
{
    if(s < 10){
        cout<<"0"<<s;
    }else{
    cout<<s;}
}

void JeuModeTexte::initTab(){
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

/*
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
*/

/*
char getCh() { // lire un caractere si une touche a ete pressee
    char touche=0;
    #ifdef _WIN32
        if (kbhit())
        {
            DWORD mode;
            DWORD n;
            HANDLE consoleI = GetStdHandle(STD_INPUT_HANDLE);
            GetConsoleMode(consoleI, &mode);
            SetConsoleMode(consoleI, mode & ~ENABLE_LINE_INPUT & ~ENABLE_ECHO_INPUT);
            ReadConsole(consoleI, &touche, 1, &n, NULL);
        }
    #else
        if (kbhit())
            touche = fgetc(stdin);
    #endif
    return touche;
}
*/

int main(){

    termClear();
    Jeu jeuUnique;
    //Taille : (50,25) / (40,20) / (60,30)
    JeuModeTexte map(60,30);

    // Création d'un stockage de ressources
    StockageRessources stockage;

    BaseCentrale base(stockage);

    BatimentDefense bat1(TypeBatiment::Tourelle);
    BatimentDefense bat2(TypeBatiment::Canon);  

    jeuUnique.tabBatDef.push_back(bat1);
    jeuUnique.tabBatDef.push_back(bat2); 

    jeuUnique.tabBatDef.at(0).setPosition(1,1);
    jeuUnique.tabBatDef.at(1).setPosition(4,4);

    //x**2 / 50   -   x / 2   +  11
    base.setPos(((map.getLargeur()/2)+0.5)-1,((map.getHauteur()*map.getHauteur())/50)-(map.getHauteur()/2)+11);
    map.affObj(base.pos,base.m_size,base.m_carac);
//
        ////////////////////////ENNEMI//////////////////////////////

    Ennemi enm1(Type_ennemi::zombi);

    //Ennemi enm2(Type_ennemi::pillard);



    jeuUnique.tabEnnemi.push_back(enm1);

   // jeuUnique.tabEnnemi.push_back(enm2);



    Vect2 pos1(15,17);

    Vect2 dire(1,0);

    jeuUnique.tabEnnemi.at(0).set_pos(pos1);

    jeuUnique.tabEnnemi.at(0).set_direction(dire);

    
/*
    Vect2 pos2(16,18);

    jeuUnique.tabEnnemi.at(1).set_pos(pos2);

    jeuUnique.tabEnnemi.at(1).set_direction(dire);*/



    ////////////////////////ENNEMI//////////////////////////////



    time_t startTime = time(NULL); // temps de départ
    time_t currentTime;
    int elapsedSeconds;
    int hours, minutes, seconds;

    Vect2 pos;
    pos.x = 0;
    pos.y = 0;
    Ennemi zombiTest;

    // Création de 3 fermes
    Ferme ferme1(stockage);
    Ferme ferme2(stockage);
    Ferme ferme3(stockage);


    //Vect2 posZombi(((map.getLargeur()/2)+0.5)-1,((map.getHauteur()*map.getHauteur())/50)-(map.getHauteur()/2)+11);
    Vect2 posZombi(12,17);
    zombiTest.set_pos(posZombi);
    Vect2 dire2(1,0);
    zombiTest.set_direction(dire2);
    jeuUnique.tabEnnemi.push_back(zombiTest);
    
     Vect2 posZombi2(11,19);
    zombiTest.set_pos(posZombi2);
    jeuUnique.tabEnnemi.push_back(zombiTest);
    //map.affObj(zombiTest.get_position(),1,'Z');

    /*ferme1.creation(pos);
    ferme2.creation(pos);
    ferme3.creation(pos);*/
    
    //BaseCentrale BC(stockage);

        // Affichage des ressources initiales
    cout << "Ressources initiales :" << endl;
    stockage.afficherRessources();
    
    //JeuModeTexte map(40,20);
    /*map.affObj(bat.getPosition(),bat.getSize(),bat.getCarac());
    map.afficher();*/


    
    // Démarrage de la production des fermes


    WinTXT win (map.getHauteur(),map.getLargeur());
    int c;

    do{
        termClear();
		usleep(100000);
        c = win.getCh();



        // obtenir le temps actuel et calculer le temps écoulé depuis le début
        currentTime = time(NULL);
        elapsedSeconds = difftime(currentTime, startTime);

        // convertir en heures, minutes et secondes
        hours = elapsedSeconds / 3600;
        minutes = (elapsedSeconds % 3600) / 60;
        seconds = elapsedSeconds % 60;

        for (unsigned int i = 0; i<jeuUnique.tabBatDef.size();i++){
        switch (jeuUnique.tabBatDef.at(i).getType()){
            case TypeBatiment::Tourelle:
                jeuUnique.tabBatDef.at(i).setSize(4);
                jeuUnique.tabBatDef.at(i).setCarac('.');
                break;
            case TypeBatiment::Canon:
                jeuUnique.tabBatDef.at(i).setSize(4); //2
                jeuUnique.tabBatDef.at(i).setCarac('.'); 
                break;            
        }

        //map.effacerObj(jeuUnique.tabBatDef.at(i).getPosition(),jeuUnique.tabBatDef.at(i).getSize());


    }
    	//map.affObj(jeuUnique.tabEnnemi.at(0).get_position(),1,'.');
    	//map.affObj(jeuUnique.tabEnnemi.at(1).get_position(),1,'.');
    	//map.affObj(jeuUnique.tabEnnemi.at(2).get_position(),1,'.');


        jeuUnique.enleveEntDestruites();
    
        //    map.affObj(jeuUnique.tabEnnemi.at(0).get_position(),1,'.');
      
        jeuUnique.deplacerEnnemis();
     //   map.affObj(jeuUnique.tabEnnemi.at(0).get_position(),1,'Z');

	    map.affObj(jeuUnique.tabEnnemi.at(0).get_position(),1,'Z');
    	map.affObj(jeuUnique.tabEnnemi.at(1).get_position(),1,'Z');
    	map.affObj(jeuUnique.tabEnnemi.at(2).get_position(),1,'Z');


        for (unsigned int i = 0; i<jeuUnique.tabBatDef.size();i++){
        switch (jeuUnique.tabBatDef.at(i).getType()){
            case TypeBatiment::Tourelle:
                jeuUnique.tabBatDef.at(i).setSize(4);
                jeuUnique.tabBatDef.at(i).setCarac('T');
                break;
            case TypeBatiment::Canon:
                jeuUnique.tabBatDef.at(i).setSize(4); //2
                jeuUnique.tabBatDef.at(i).setCarac('C'); 
                break;            
        }
        map.affObj(jeuUnique.tabBatDef.at(i).getPosition(),jeuUnique.tabBatDef.at(i).getSize(),jeuUnique.tabBatDef.at(i).getCarac());

    }


        //afficher toutes les entites

        map.afficher();
        map.initTab();


        // afficher le timer
        cout << "Temps écoulé : ";
        H(hours);
        cout << ":";
        M(minutes);
        cout << ":";
        S(seconds);
        cout << endl;

        
        /*ferme1.degat(1);
        ferme2.degat(2);
        ferme3.degat(3);*/

        //BC.degat(50);
        
        ferme1.production(ferme1.est_vivant());
        ferme2.production(ferme2.est_vivant());
        ferme3.production(ferme3.est_vivant());

        //BC.production(BC.est_vivant());
        
        //cout << "                                       Ressources actuel :" << endl;
        stockage.afficherRessources();
        
        
        /*cout << "****************************Gestion Ennemi's" <<endl;

        jeuUnique.tabEnnemi.at(0).afficher();*/

        cout << "****************************Gestion BatimentDefense's" <<endl;

        cout << "Batiment N° " << 0 <<endl;
       
	    cout<<" --- STATUS BATIMENTS --- "<<endl;
        jeuUnique.tabBatDef.at(0).afficher();
        
        jeuUnique.tabBatDef.at(1).afficher();

        if (c == 'm'){
            char ch;
            int x,y;
            cout << "Menu: " <<endl;
            cout << "1.Pour construire un batiment" <<endl;
            cout << "2.Pour quitter" <<endl;
            cin >> ch;
            switch (ch){
                case '1':
                {
                    cout << jeuUnique.tabBatDef.size() <<endl;  
                    cout << "Donner la coord x: "; cin >> x; cout << endl;
                    cout << "Donner la coord y: "; cin >> y;
                    BatimentDefense bat(TypeBatiment::Tourelle);
                    jeuUnique.tabBatDef.push_back(bat); 
                    jeuUnique.tabBatDef.at(jeuUnique.tabBatDef.size()-1).setPosition(y,x);
                    map.affObj(jeuUnique.tabBatDef.at(jeuUnique.tabBatDef.size()-1).getPosition(),4,'T');
                    break;
                }
                case '2':
                {
                    c = 'q';
                    break;
                }
                default:
                {
                    cout << "MENU ERROR" <<endl;
                    break;
                }
            }
        }
    }while (c != 'q');
    
    // Affichage des ressources finales
    /*cout << "                                       Ressources actuel :" << endl;
    stockage.afficherRessources();*/

    return 0;
}
