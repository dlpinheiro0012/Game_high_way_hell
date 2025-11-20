#ifndef CONSTANTES_H
#define CONSTANTES_H
#include "raylib.h"

typedef enum{
    MENU_INICIAL, // 0
    CREDITOS,     // 1
    LORE1,        // 2
    FASE1,        // 3
}Screen;

extern int larguraTela;

extern int alturaTela;

void InitConfigTela();

extern const Color CorBackGroundFase1;

#endif
