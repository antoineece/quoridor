#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>


#define #include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>


#define NOM_FICHIER "partie_sauvegardee.txt"


void sauvegarder_partie(const Jeu *jeu) {
   FILE *fichier = fopen(NOM_FICHIER, "w");
   if (fichier) {
       fprintf(fichier, "%d %d %d %d\n", jeu->joueur1_x, jeu->joueur1_y, jeu->joueur2_x, jeu->joueur2_y);
       fprintf(fichier, "%d %d\n", jeu->murs_joueur1, jeu->murs_joueur2);
       for (int i = 0; i < TAILLE_PLATEAU; i++) {
           for (int j = 0; j < TAILLE_PLATEAU; j++) {
               fprintf(fichier, "%c", jeu->plateau[i][j]);
           }
           fprintf(fichier, "\n");
       }
       fclose(fichier);
       printf("Partie sauvegardée avec succès !\n");
   } else {
       printf("Erreur lors de la sauvegarde.\n");
   }
}


void charger_partie(Jeu *jeu) {
   FILE *fichier = fopen(NOM_FICHIER, "r");
   if (fichier) {
       fscanf(fichier, "%d %d %d %d", &jeu->joueur1_x, &jeu->joueur1_y, &jeu->joueur2_x, &jeu->joueur2_y);
       fscanf(fichier, "%d %d", &jeu->murs_joueur1, &jeu->murs_joueur2);
       for (int i = 0; i < TAILLE_PLATEAU; i++) {
           for (int j = 0; j < TAILLE_PLATEAU; j++) {
               fscanf(fichier, " %c", &jeu->plateau[i][j]);
           }
       }
       fclose(fichier);
       printf("Partie chargée avec succès !\n");
   } else {
       printf("Aucune sauvegarde trouvée.\n");
       initialiser_plateau(jeu);
   }
}


void menu(Jeu *jeu) {
   int choix;
   do {
       printf("\nMenu principal :\n");
       printf("1. Nouvelle partie\n");
       printf("2. Reprendre une partie\n");
       printf("3. Afficher l'aide\n");
       printf("4. Afficher les scores\n");
       printf("5. Quitter\n");
       printf("Votre choix : ");
       scanf("%d", &choix);


       switch (choix) {
           case 1:
               initialiser_plateau(jeu);
               return;
           case 2:
               charger_partie(jeu);
               return;
           case 3:
               printf("\nAide du jeu :\n");
               printf("- Déplacez votre pion pour atteindre le bord opposé.\n");
               printf("- Placez des barrières pour ralentir votre adversaire.\n");
               printf("- Entrez les coordonnées dans le format demandé.\n");
               break;
           case 4:
               printf("Scores : Joueur 1 = %d, Joueur 2 = %d\n", jeu->scores_joueur1, jeu->scores_joueur2);
               break;
           case 5:
               printf("Au revoir !\n");
               exit(0);
           default:
               printf("Choix invalide !\n");
       }
   } while (1);
}
NOM_FICHIER "partie_sauvegardee.txt"



   
