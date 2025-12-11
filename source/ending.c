#include "ending.h"

int boolLoadedEnd = 0;// Flag para verificar se as imagens foram carregadas
static Texture2D textureEnd;

void InitEnding(Screen* screenSelector) {
    
    if(boolLoadedEnd == 0) {
        textureEnd = LoadAnyTexture("assets/imagens/ending.png");
        boolLoadedEnd = 1;
    }
    
    SetTargetFPS(60);
    BeginDrawing();
    
        ClearBackground(BLACK);
        DrawTexture(textureEnd, 0, 0, WHITE);

        DrawTextDigitado("'I-Impossível... Isso... Não pode ser...'", larguraTela/15, alturaTela/7, 35, YELLOW,1); DrawTextDigitado("- disse Jobos, caído no chão, derrotado.", larguraTela/15 + 630, alturaTela/7, 35, WHITE,1);
        DrawTextDigitado("Vasculhando seus pertences, você encontra as chaves para a cela de Alexandrina, agora liberta.", larguraTela/15, alturaTela/5, 35, WHITE,1);
        DrawTextDigitado("Assim, juntos, vocês roubam a moto de uma caveira motoqueira, e fogem do Império da Maçã.", larguraTela/15, alturaTela/4, 35, WHITE,0.6);
        DrawTextDigitado("A paz em Motorolos é restaurada, enquanto o Império encontrou sua própria ruína.", larguraTela/15, alturaTela/3, 35, WHITE,0.6);
        DrawTextDigitado("FIM!", larguraTela/15, alturaTela/2, 35, WHITE,0.6);

        DrawTextDigitado("Pressione H para os créditos!", larguraTela/15, 1.5 * alturaTela / 2, 30, WHITE,0.6);

    EndDrawing();

    if(IsKeyPressed(KEY_H)){
        boolLoadedEnd = 0;
        UnloadTexture(textureEnd);
        *screenSelector = CREDITOS;
        return;
    }
}