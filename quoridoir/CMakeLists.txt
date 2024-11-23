cmake_minimum_required(VERSION 3.29)
project(quoridoir C)

set(CMAKE_C_STANDARD 23)

add_executable(quoridoir ../main.c
        ../plateau.c
        ../plateau.h
        ../jeu.c
        ../jeu.h
        ../sauvegarde.c
        ../sauvegarde.h
)
