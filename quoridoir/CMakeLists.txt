cmake_minimum_required(VERSION 3.29)
project(quoridoir C)

set(CMAKE_C_STANDARD 23)

add_executable(quoridoir ../main.c
        plateau.c
        plateau.h
        deplacements.c
        deplacements.h
        "placement murs.c"
        "placement murs.h"
        "initialisation des joueurs.c"
        "initialisation des joueurs.h"
        "afficher le plateau.c"
        "afficher le plateau.h"
        "verif gagnant.c"
        "verif gagnant.h")
