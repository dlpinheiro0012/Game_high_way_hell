#include "raylib.h"
#include "constantes.h"
#include "load.h"
#include "fase1.h"

void InitFase_1(const int larguraTela, const int alturaTela){
    BeginDrawing();
        ClearBackground(CorBackGroundFase1);
        DrawRectangle(0, 3*(alturaTela / 4), larguraTela, larguraTela / 4, BLACK);
        DrawRectangle(80, (alturaTela / 8) * 2, 70, 500, GREEN);
    EndDrawing();
}

void JogarFase_1(){

}