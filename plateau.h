#include "plateauint.h"
#include <stdio.h>


void initialiser_plateau(Jeu *jeu) {
   for (int i = 0; i < TAILLE_PLATEAU; i++) {
       for (int j = 0; j < TAILLE_PLATEAU; j++) {
           jeu->plateau[i][j] = ' ';
       }
   }
   jeu->joueur1_x = 0; jeu->joueur1_y = 4;
   jeu->joueur2_x = 8; jeu->joueur2_y = 4;
   jeu->murs_joueur1 = MURS;
   jeu->murs_joueur2 = MURS;
   jeu->scores_joueur1 = 0;
   jeu->scores_joueur2 = 0;


   jeu->plateau[jeu->joueur1_x][jeu->joueur1_y] = '1';
   jeu->plateau[jeu->joueur2_x][jeu->joueur2_y] = '2';
}


void afficher_plateau(const Jeu *jeu) {
   printf("\n  ");
   for (int j = 0; j < TAILLE_PLATEAU; j++) {
       printf("%d ", j);
   }
   printf("\n");
   for (int i = 0; i < TAILLE_PLATEAU; i++) {
       printf("%d ", i);
       for (int j = 0; j < TAILLE_PLATEAU; j++) {
           printf("%c ", jeu->plateau[i][j]);
       }
       printf("\n");
   }
}
