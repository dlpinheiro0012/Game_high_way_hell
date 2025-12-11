#include "lore.h"

int boolLoadedLore = 0;// Flag para verificar se as imagens foram carregadas
static Texture2D textureLore;// Textura para o lore

void InitLore(Screen* screenSelector) {

    if(boolLoadedLore == 0) {
        textureLore = LoadAnyTexture("assets/imagens/background_desert.png");
        boolLoadedLore = 1;
    }

    SetTargetFPS(60);
    BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(textureLore, 0, 0, WHITE);

        DrawTextDigitado("O Reino de Motorolos entrou em caos quando a princesa", larguraTela/15, alturaTela/7, 45, BLACK,1);
        DrawTextDigitado("Alexandrina foi raptada por Jobos, tirano do inferno da maçã.", larguraTela/15, alturaTela/5.5, 45, BLACK,0.6);

        DrawTextDigitado("Você, um herói imperativo, deve atravessar os dois vales de Cinlândia", larguraTela/15, alturaTela/4, 45, BLACK,0.6);
        DrawTextDigitado("e descer rumo ao recanto de jobos para resgatá-la o mais rápido possivel!.", larguraTela/15, alturaTela/3.5, 45, BLACK,0.6);

        DrawTextDigitado("Primeiro, googlios, um servo inferior, preparou uma barreira", larguraTela/15, alturaTela/2.8, 45, BLACK,0.6);
        DrawTextDigitado("impenetrável... Vença-a e siga HIGH WAY TO HELL!!!", larguraTela/15, alturaTela/2.5, 45, BLACK,0.6);

        DrawTextDigitado("Pressione D para atingir seu inimigo", larguraTela/15, 1.5 * alturaTela / 2, 30, RED,0.6);
        DrawTextDigitado("Pressione H para começar", larguraTela/15, 1.5 * alturaTela / 1.9, 30, RED,0.6);

    EndDrawing();

    if(IsKeyPressed(KEY_H)){
        boolLoadedLore = 0;
        UnloadTexture(textureLore);
        *screenSelector = FASE1;
        return;
    }
}
