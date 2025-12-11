#include "interludio.h"

int boolLoadedInterludio = 0;// Flag para verificar se as imagens foram carregadas
static Texture2D textureInterludio;// Textura para o interlúdio

void InitInterludio(Screen* screenSelector) {
    
    if(boolLoadedInterludio == 0) {
        textureInterludio = LoadAnyTexture("assets/imagens/background_castle.png");
        boolLoadedInterludio = 1;
    }
    
    SetTargetFPS(60);
    BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(textureInterludio, 0, 0, WHITE);

        DrawTextDigitado("A luta foi árdua, mas você conseguiu derrotar Googlios. Em seu leito de morte, o demônio disse:", larguraTela/15 - 100, alturaTela/7, 35, WHITE,1);
        DrawTextDigitado("'Eu já cumpri meu papel... Você nunca derrotará Jobos, mortal! Ele usará Alexandrina e seus poderes", larguraTela/15 - 100, alturaTela/5, 35, YELLOW,1);
        DrawTextDigitado("recursivos para dominar toda Motorolos! Não há nada que você possa fazer!'", larguraTela/15 - 100, alturaTela/4, 35, YELLOW,0.6);

        DrawTextDigitado("Então um portal surge, revelando o Inferno da Maçã. No horizonte, um castelo - o ICastle, o lugar", larguraTela/15 - 100, alturaTela/3.4, 35, WHITE,0.6);
        DrawTextDigitado("em que ele mantém a princesa presa. Para libertá-la, você deve derrotar Jobos de uma vez por todas.", larguraTela/15 - 100, alturaTela/2.9, 35, WHITE,0.6);
        
        DrawTextDigitado("No momento em que você entra nessa dimensão, a voz de Jobos ecoa:", larguraTela/15 - 100, alturaTela/2.5, 35, WHITE,0.6);
        DrawTextDigitado("'Seus esforços são inúteis, aventureiro. Acaberei com você com minhas próprias mãos!'", larguraTela/15 - 100, alturaTela/2.2, 35, YELLOW,0.6);

        DrawTextDigitado("Pressione D para atingir seu inimigo", larguraTela/15 - 100, 1.5 * alturaTela / 2, 30, RED,0.6);
        DrawTextDigitado("Pressione H para começar", larguraTela/15 - 100, 1.5 * alturaTela / 1.9, 30, RED,0.6);
    EndDrawing();

    if(IsKeyPressed(KEY_H)){
        
        boolLoadedInterludio = 0;
        UnloadTexture(textureInterludio);
        *screenSelector = FASE2;
        return;
    }
}