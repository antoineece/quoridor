#include "jeu.h"
#include <stdio.h>

void jouer_deplacement(Jeu *jeu, int joueur, int x, int y) {


   if (x < 0 || x >= TAILLE_PLATEAU || y < 0 || y >= TAILLE_PLATEAU) {
       printf("Deplacement invalide : Hors du plateau !\n");
       return;
   }
   int *joueur_x = (joueur == 1) ? &jeu->joueur1_x : &jeu->joueur2_x;
   int *joueur_y = (joueur == 1) ? &jeu->joueur1_y : &jeu->joueur2_y;
   if (((*joueur_x == x) && (abs(*joueur_y - y) == 1)) || ((*joueur_y == y) && (abs(*joueur_x - x) == 1))) {


       if (jeu->plateau[x][y] == ' ') {


           jeu->plateau[*joueur_x][*joueur_y] = ' ';
           *joueur_x = x;
           *joueur_y = y;
           jeu->plateau[x][y] = (joueur == 1) ? '1' : '2';  // Mettre à jour la case de destination
       } else {
           printf("Deplacement invalide : Case occupee !\n");
       }
   } else {
       printf("Deplacement invalide : Vous devez vous deplacer d'une seule case horizontalement ou verticalement.\n");
   }
}



void jouer_mur(Jeu *jeu, int joueur, int x1, int y1, int x2, int y2) {
   if (x1 >= 0 && x1 < TAILLE_PLATEAU && y1 >= 0 && y1 < TAILLE_PLATEAU &&
       x2 >= 0 && x2 < TAILLE_PLATEAU && y2 >= 0 && y2 < TAILLE_PLATEAU &&
       jeu->plateau[x1][y1] == ' ' && jeu->plateau[x2][y2] == ' ') {
       if (joueur == 1 && jeu->murs_joueur1 > 0) {
           jeu->plateau[x1][y1] = '|';
           jeu->plateau[x2][y2] = '|';
           jeu->murs_joueur1--;
       } else if (joueur == 2 && jeu->murs_joueur2 > 0) {
           jeu->plateau[x1][y1] = '|';
           jeu->plateau[x2][y2] = '|';
           jeu->murs_joueur2--;
       } else {
           printf("Placement de mur invalide ou plus de murs disponibles !\n");
       }
       } else {
           printf("Position invalide pour le mur !\n");
       }
}


int verifier_gagnant(const Jeu *jeu) {
   if (jeu->joueur1_x == TAILLE_PLATEAU - 1) {
       return 1; // Joueur 1 gagne
   } else if (jeu->joueur2_x == 0) {
       return 2; // Joueur 2 gagne
   }
   return 0; // Pas encore de gagnant
}
