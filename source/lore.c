#include "lore.h"

void InitLore(Screen* screenSelector) {
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(BLACK);

    DrawTextDigitado("O Reino de Motorolos entrou em caos quando a princesa", larguraTela/10, alturaTela/7, 30, WHITE,1);
    DrawTextDigitado("Alexandrina foi raptada por Jobos, tirano do inferno da maçã.", larguraTela/10, alturaTela/5.5, 30, WHITE,0.6);

    DrawTextDigitado("Você, um herói imperativo, deve atravessar os dois vales de Cinlândia", larguraTela/10, alturaTela/4, 30, WHITE,0.6);
    DrawTextDigitado("e descer rumo ao recanto de jobos para resgatá-la o mais rápido possivel!.", larguraTela/10, alturaTela/3.5, 30, WHITE,0.6);

    DrawTextDigitado("Primeiro, googlios, um servo inferior, preparou uma barreira", larguraTela/10, alturaTela/2.8, 30, WHITE,0.6);
    DrawTextDigitado("impenetrável... Vença-a e siga HIGH WAY TO HELL!!!", larguraTela/10, alturaTela/2.5, 30, WHITE,0.6);

    DrawTextDigitado("Pressione D para atingir seu inimigo", larguraTela/10, alturaTela/2, 20, RED,0.6);
    DrawTextDigitado("Pressione H para começar", larguraTela/10, alturaTela/1.9, 20, RED,0.6);

    EndDrawing();

    if(IsKeyPressed(KEY_H)){
        *screenSelector = FASE1;
    }
}
