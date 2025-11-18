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
    EndDrawing();
}