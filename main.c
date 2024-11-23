#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_PLATEAU 9
#define MURS 10
#define NOM_FICHIER "partie_sauvegardee.txt"

// Structure pour regrouper toutes les données du jeu
typedef struct {
    char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
    int joueur1_x, joueur1_y;
    int joueur2_x, joueur2_y;
    int murs_joueur1, murs_joueur2;
    int scores_joueur1, scores_joueur2;
} Jeu;

// Initialisation du plateau
void initialiser_plateau(Jeu *jeu) {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            jeu->plateau[i][j] = ' ';
        }
    }
    jeu->joueur1_x = 0;
    jeu->joueur1_y = 4;
    jeu->joueur2_x = 8;
    jeu->joueur2_y = 4;
    jeu->murs_joueur1 = MURS;
    jeu->murs_joueur2 = MURS;
    jeu->scores_joueur1 = 0;
    jeu->scores_joueur2 = 0;
    jeu->plateau[jeu->joueur1_x][jeu->joueur1_y] = '1';
    jeu->plateau[jeu->joueur2_x][jeu->joueur2_y] = '2';
}

// Affichage du plateau
void afficher_plateau(Jeu *jeu) {
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

// Sauvegarde de la partie
void sauvegarder_partie(Jeu *jeu) {
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

// Chargement de la partie sauvegardée
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

// Vérification du gagnant
int verifier_gagnant(Jeu *jeu) {
    if (jeu->joueur1_x == TAILLE_PLATEAU - 1) {
        jeu->scores_joueur1++;
        printf("Le joueur 1 a gagné !\n");
        return 1;
    } else if (jeu->joueur2_x == 0) {
        jeu->scores_joueur2++;
        printf("Le joueur 2 a gagné !\n");
        return 2;
    }
    return 0;
}

// Déplacement des joueurs
void jouer_deplacement(Jeu *jeu, int joueur, int x, int y) {
    if (x >= 0 && x < TAILLE_PLATEAU && y >= 0 && y < TAILLE_PLATEAU && jeu->plateau[x][y] == ' ') {
        if (joueur == 1) {
            jeu->plateau[jeu->joueur1_x][jeu->joueur1_y] = ' ';
            jeu->joueur1_x = x;
            jeu->joueur1_y = y;
            jeu->plateau[x][y] = '1';
        } else if (joueur == 2) {
            jeu->plateau[jeu->joueur2_x][jeu->joueur2_y] = ' ';
            jeu->joueur2_x = x;
            jeu->joueur2_y = y;
            jeu->plateau[x][y] = '2';
        }
    } else {
        printf("Déplacement invalide !\n");
    }
}

// Placement des murs
void jouer_mur(Jeu *jeu, int joueur, int x1, int y1, int x2, int y2) {
    if (x1 >= 0 && x1 < TAILLE_PLATEAU && y1 >= 0 && y1 < TAILLE_PLATEAU &&
        x2 >= 0 && x2 < TAILLE_PLATEAU && y2 >= 0 && y2 < TAILLE_PLATEAU &&
        jeu->plateau[x1][y1] == ' ' && jeu->plateau[x2][y2] == ' ') {
        if (joueur == 1 && jeu->murs_joueur1 > 0) {
            jeu->plateau[x1][y1] = 'B';
            jeu->plateau[x2][y2] = 'B';
            jeu->murs_joueur1--;
        } else if (joueur == 2 && jeu->murs_joueur2 > 0) {
            jeu->plateau[x1][y1] = 'B';
            jeu->plateau[x2][y2] = 'B';
            jeu->murs_joueur2--;
        } else {
            printf("Pas assez de murs !\n");
        }
    } else {
        printf("Position invalide pour le mur !\n");
    }
}

// Afficher le menu d'aide
void afficher_aide() {
    printf("\nAide du jeu :\n");
    printf("- Déplacez votre pion pour atteindre le bord opposé.\n");
    printf("- Placez des barrières pour ralentir votre adversaire.\n");
    printf("- Entrez les coordonnées dans le format demandé.\n");
    printf("\n");
}

// Menu principal
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
                afficher_aide();
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

int main() {
    Jeu jeu; // Créer une instance de la structure Jeu
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

    return 0;
}
