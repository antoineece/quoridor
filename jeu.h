#ifndef JEU_H
#define JEU_H


#include "plateauint.h"


// Fonction pour déplacer un joueur
void jouer_deplacement(Jeu *jeu, int joueur, int x, int y);


// Fonction pour placer un mur
void jouer_mur(Jeu *jeu, int joueur, int x1, int y1, int x2, int y2);


// Vérifie si un joueur a gagné
int verifier_gagnant(const Jeu *jeu);


#endif // JEU_H
