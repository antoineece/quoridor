#ifndef PLATEAU_H
#define PLATEAU_H

#define TAILLE_PLATEAU 9
#define MURS 10

typedef struct {
    char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
    int joueur1_x, joueur1_y;
    int joueur2_x, joueur2_y;
    int murs_joueur1, murs_joueur2;
    int scores_joueur1, scores_joueur2;
} Jeu;

void initialiser_plateau(Jeu *jeu);
void afficher_plateau(Jeu *jeu);

#endif // PLATEAU_H