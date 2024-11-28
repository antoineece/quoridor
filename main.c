#include "plateauint.h"
#include "sauvegarde.h"
#include "jeu.h"
#include <stdio.h>


int main() {
   Jeu jeu;
   menu(&jeu);


   int gagnant = 0;
   while (!gagnant) {
       afficher_plateau(&jeu);


       int choix, joueur, x1, y1, x2, y2;
       printf("1. Déplacer un joueur\n");
       printf("2. Placer un mur\n");
       printf("3. Sauvegarder et revenir au menu\n");
       printf("Votre choix : ");
       scanf("%d", &choix);


       if (choix == 1) {
           printf("Entrez le joueur (1 ou 2) et les coordonnées (x y) : ");
           scanf("%d %d %d", &joueur, &x1, &y1);
           jouer_deplacement(&jeu, joueur, x1, y1);
       } else if (choix == 2) {
           printf("Entrez le joueur (1 ou 2) et les coordonnées des deux cases (x1 y1 x2 y2) : ");
           scanf("%d %d %d %d %d", &joueur, &x1, &y1, &x2, &y2);
           jouer_mur(&jeu, joueur, x1, y1, x2, y2);
       } else if (choix == 3) {
           sauvegarder_partie(&jeu);
           menu(&jeu);
       }


       gagnant = verifier_gagnant(&jeu);
   }


   printf("Félicitations au joueur %d pour sa victoire !\n", gagnant);
   return 0;
}

/*
1. KooR.fr
2. OpenClassrooms - Apprenez à programmer en C
3. GeeksforGeeks - C Programming
4. Git - Documentation officielle
5. ECE Paris - Projet Informatique 1
6. Quoridor - GitHub
7. Gamecodeur - Demo Reel 2021-2022
*/

