#include "ending.h"

void InitEnding(Screen* screenSelector) {
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(BLACK);

    DrawTextDigitado("Depois de derrotar Jobos, você resgatou Alexandrina de seu cativeiro", larguraTela/15, alturaTela/7, 35, WHITE,1);
    DrawTextDigitado("e roubou a moto de uma caveira flamejante que estava bobeando no inferno,", larguraTela/15, alturaTela/5, 35, WHITE,1);
    DrawTextDigitado("finalmente escapando do Inferno da Maçã.", larguraTela/15, alturaTela/4, 35, WHITE,0.6);
    
    DrawTextDigitado("Pressione H para os créditos!", larguraTela/15, 1.5 * alturaTela / 2, 30, RED,0.6);

    EndDrawing();

    if(IsKeyPressed(KEY_H)){
        *screenSelector = CREDITOS;
    }
}