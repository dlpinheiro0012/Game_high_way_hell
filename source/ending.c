#include "ending.h"

int boolLoadedEnd = 0;// Flag para verificar se as imagens foram carregadas

void InitEnding(Screen* screenSelector) {
    static Texture2D textureGoodEnd;
    
    if(boolLoadedEnd == 0) {
        textureGoodEnd = LoadAnyTexture("assets/imagens/ending.png");
        boolLoadedEnd = 1;
    }
    
    SetTargetFPS(60);
    BeginDrawing();
        DrawTexture(textureGoodEnd, 0, 0, WHITE);

        DrawTextDigitado("Depois de derrotar Jobos, você resgatou Alexandrina de seu cativeiro", larguraTela/15, alturaTela/7, 35, WHITE,1);
        DrawTextDigitado("e roubou a moto de uma caveira flamejante que estava bobeando no inferno,", larguraTela/15, alturaTela/5, 35, WHITE,1);
        DrawTextDigitado("finalmente escapando do Inferno da Maçã.", larguraTela/15, alturaTela/4, 35, WHITE,0.6);

        DrawTextDigitado("Pressione H para os créditos!", larguraTela/15, 1.5 * alturaTela / 2, 30, WHITE,0.6);

    EndDrawing();

    if(IsKeyPressed(KEY_H)){
        *screenSelector = CREDITOS;
        UnloadTexture(textureGoodEnd);
    }
}