#ifndef FASE_1_H
#define FASE_1_H
#include "raylib.h"
#include "constantes.h"
#include "load.h"

typedef struct{
    Texture2D stand;
    Texture2D fight;
}Person;

void InitFase_1(Screen* screenSelector);

#endif