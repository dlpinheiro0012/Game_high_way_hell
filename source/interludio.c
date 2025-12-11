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

        DrawTextDigitado("A luta foi árdua, mas você conseguiu derrotar Googlios.", larguraTela/15, alturaTela/7, 35, WHITE,1);
        DrawTextDigitado("Em seu leito de morte, o demônio disse:", larguraTela/15, alturaTela/5, 35, WHITE,1);
        DrawTextDigitado("'Eu já cumpri meu papel... Você nunca derrotará Jobos, mortal!", larguraTela/15, alturaTela/4, 35, YELLOW,0.6);
        DrawTextDigitado("Renda-se se preza pela sua vida!'", larguraTela/15, alturaTela/3.4, 35, YELLOW,0.6);
        DrawTextDigitado("Então, diante de você se revela o outro lado - o ICastle, o castelo do infame Jobos,", larguraTela/15, alturaTela/2.9, 35, WHITE,0.6);
        DrawTextDigitado("que ainda mantém presa sua amada Alexandrina.", larguraTela/15, alturaTela/2.5, 35, WHITE,0.6);
        DrawTextDigitado("Nesse momento, você entra no portal, pronto para a batalha final.", larguraTela/15, alturaTela/2.2, 35, WHITE,0.6);

        DrawTextDigitado("Pressione D para atingir seu inimigo", larguraTela/15, 1.5 * alturaTela / 2, 30, RED,0.6);
        DrawTextDigitado("Pressione H para começar", larguraTela/15, 1.5 * alturaTela / 1.9, 30, RED,0.6);
    EndDrawing();

    if(IsKeyPressed(KEY_H)){
        
        boolLoadedInterludio = 0;
        UnloadTexture(textureInterludio);
        *screenSelector = FASE2;
        return;
    }
}