#include "interludio.h"

void InitInterludio(Screen* screenSelector) {
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(BLACK);

    DrawTextDigitado("A luta foi árdua, mas você conseguiu derrotar Googlios com todas as suas forças. Em seu leito de morta, o demônio disse:", larguraTela/15, alturaTela/7, 45, WHITE,1);
    DrawTextDigitado("'Eu já cumpri meu papel... Você nunca derrotará Jobos, mortal! Renda-se e preze pela sua vida!'", larguraTela/15, alturaTela/5.5, 45, WHITE,0.6);

    DrawTextDigitado("'Então, diante de você, uma fenda dimensional surge, onde se revela o outro lado - o Inferno da Maçã -'", larguraTela/15, alturaTela/4, 45, WHITE,0.6);
    DrawTextDigitado("e no horizonte flamejante e vermelho, o ICastelo de Jobos, onde Alexandrina ainda é mantida presa.", larguraTela/15, alturaTela/3.5, 45, WHITE,0.6);

    DrawTextDigitado("", larguraTela/15, alturaTela/2.8, 45, WHITE,0.6);
    DrawTextDigitado("impenetrável... Vença-a e siga HIGH WAY TO HELL!!!", larguraTela/15, alturaTela/2.5, 45, WHITE,0.6);

    DrawTextDigitado("Pressione D para atingir seu inimigo", larguraTela/15, 1.5 * alturaTela / 2, 30, RED,0.6);
    DrawTextDigitado("Pressione H para começar", larguraTela/15, 1.5 * alturaTela / 1.9, 30, RED,0.6);

    EndDrawing();

    if(IsKeyPressed(KEY_H)){
        *screenSelector = FASE2;
    }
}