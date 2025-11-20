#ifndef FASE_1_H
#define FASE_1_H
#include "raylib.h"
#include "constantes.h"
#include "load.h"

typedef struct{
    int hp;
    int score;
}Player;

void InitFase_1(Screen* screenSelector);

#endif