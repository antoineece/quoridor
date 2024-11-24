#ifndef JEU_H
#define JEU_H


#include "plateauint.h"


void jouer_deplacement(Jeu *jeu, int joueur, int x, int y);



void jouer_mur(Jeu *jeu, int joueur, int x1, int y1, int x2, int y2);



int verifier_gagnant(const Jeu *jeu);


#endif 
