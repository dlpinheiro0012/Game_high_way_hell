#include "raylib.h"
#include "constantes.h"
#include "load.h"

typedef struct{
    int hp;
    int score;
}Player;

void InitFase_1(){
    BeginDrawing();
        ClearBackground(CorBackGroundFase1);
        DrawRectangle(0, 3*(alturaTela / 4), larguraTela, larguraTela / 4, BLACK);
    EndDrawing();
}