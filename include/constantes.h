#ifndef CONSTANTES_H
#define CONSTANTES_H
#include "raylib.h"

typedef enum{
    MENU_INICIAL, // 0
    CREDITOS,     // 1
    LORE1,        // 2
    FASE1,        // 3
    INTERLUDIO,   // 4
    FASE2,        // 5
    GAME_OVER,    // 6
    ENDING        // 7  
}Screen;

typedef void (*Selector)(Screen* screenSelector);

extern const int larguraTela;
extern const int alturaTela;

extern const Color CorBackGroundFase1;

#endif
