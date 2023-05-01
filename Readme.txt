# Readme

Ce jeu a été fait dans le cadre du projet de LIFAPCD par :

M. BOUHEDDADJ Ahmed (p2111020)

Mme. VEGA Sara (p2105542)

M. COTTIER Alexandre (p2018147) 

Le lien du git est :[https://forge.univ-lyon1.fr/p2018147/projet-lifapcd ](https://forge.univ-lyon1.fr/p2018147/projet-lifapcd)

## Commandes de compilation et d'exécution :
Le jeu compile que sous Linux.

SDL2 doit être instalé dans l’ordinateur, pour l’instaler, faire la commande : 
```bash
sudo apt install python3 valgrind doxygen libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick
```

	
Pour compiler le jeu, il faut se placer dans le répertoire racine du projet, contenant les dossiers src, bin, data, ... 

Lancez dans le terminal la commande 
```bash
make 
```
puis tapez 
```bash
./bin/jeu 
```
pour la version textuelle du jeu et 
```bash
./bin/gr 
```
 pour la version graphique.

## Le manuel 
### Principe et règles du jeu : 
Le jeu commence avec l’apparition du menu principale avec ses options : 
Jouer, option et crédit. 
Dans le contexte où le joueur sélectionne le bouton “Jouer”, le jeu lancera une nouvelle sauvegarde totalement neuve et entamera le tutoriel (suite décrite plus tard). 
Dans le contexte où le joueur sélectionne le bouton “Option”, le joueur pourra décider de baisser le son du jeu et de modifier la langue du jeu. 
Dans le contexte où le joueur sélectionne le bouton “Crédits”, les noms des développeurs du jeu s’afficheront à l'écran. 

### MAP :
La carte possède 3 chemins principaux : OUEST, EST, SUD, au milieu se trouve la ferme principale du joueur (celle qu’il doit protéger à tout pris) et tout autour un rayon qui permet au joueur de construire ce qu’il veut.

### GAMEPLAY :
L’objectif du joueur est de survivre le plus longtemps possible à une invasion zombi avec des vagues l’ennemis.

La base qui se trouve au centre est la base centrale du joueur il devra la protéger, pour cela il devra créer des bâtiments de défense et fermes avec les ressources disponibles.

Un système de vague est implémenté et fera apparaître des ennemi (appelé ennemi principaux) tout les X temps (temps non constant et variera selon l’importance de la vague précédente), a partir d’une certaine vague d’autre type d’ennemi (appeler ennemi secondaire) apparaîtront non pas sur les 3 chemins mais sur les 4 côtés (bas gauche, bas droite, haut gauche, haut droite) et seront beaucoup moins dangereux et nombreux que les ennemis principaux mais ne seront pas à négliger, leurs but est toujours d’atteindre la ferme principale pour la détruire mais passeront par les fermes pour piller/infecter les ressources du joueur, pour plus de détails sur les ennemi principaux et secondaire, se référer à la page détaillants les ennemis. 

Les bâtiments sont différenciés de par leurs types et leurs niveaux, il existe plusieurs types de bâtiments : les tours de guets, les tourelles automatiques, les tours automatiques, ils serviront à défendre  le territoire du joueur et devront être placés avec stratégie. 

Parmi les bâtiments, un type nommé “ferme” se distingue par le fait qu’il sert à créer des ressources supplémentaires, le but est bien évidemment d'accroître ses ressources et son expansion en défendant sa ferme principale puis ses fermes secondaires, ses fermes secondaires généreront des ressources supplémentaires.

Si la Base Centrale n’a plus de points de vie le jeu se termine, l’utilisateur a perdu.

#### Menu
Dans la version graphique on a accès au menu au début du jeu et on a une boutique pendant la partie pour acheter les bâtiments et améliorations, pour fermer le jeu appuyer sur la touche a ou sur le ‘x’ de l’écran.

Dans la version textuelle appuyer la touche m pour accéder au menu, pour fermer le jeu appuyer sur la touche m puis la touche q.

## Description de l'organisation de l'archive 
L’archive a un dossier racine contant le makefile et les dossiers :

- scr, contenant tout le code, le noyau et les version texte et graphique du jeu

- data, les assets (les images, sons, fontes)

- bin, répertoire ou les exécutables sont compilées

- obj, répertoire contenant les compilations intermédiaires
doc, le fichier dioxygène qui permet de générer la documentation du code

### L’organisation des fichiers est la suivante 
* scr/BatimentDefence, scr/Ennemi ,scr/Ferme, src/Jeu, scr/StockageRessources, scr/Vect2 

sont les classes qui constituent le noyau du jeu.

* scr/JeuModeGraphique scr/sdlJeu 

sont les classes qui font tourner le jeu et l’afficher dans la console

* scr/JeuModeTexte scr/winTxt 

sont les classes qui font tourner le jeu et l’afficher avec SDL2
