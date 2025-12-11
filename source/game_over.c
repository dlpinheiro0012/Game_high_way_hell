#include "game_over.h"

int boolLoadedGameOver = 0;// Flag para verificar se as imagens foram carregadas
static Texture2D textureGameOver;// Textura para o game over

void InitGameOver(Screen *screenSelector){
    SetTargetFPS(60);

    if(boolLoadedGameOver == 0) {
        textureGameOver = LoadAnyTexture("assets/imagens/main_character_defeat.png");
        boolLoadedGameOver = 1;
    }

    BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(textureGameOver, 0, 0, WHITE);

        char* line_1 = "O guerreiro infelizmente cedeu, e";
        char* line_2 = "agora a tirania da maçã continuará a reinar.";
        char* line_3 = "O mundo está perdido...";
        char* line_4 = "Pressione espaço para voltar ao menu";

        DrawText(line_1, (larguraTela - MeasureText(line_1, 60))/2, alturaTela/6, 60, WHITE);
        DrawText(line_2, (larguraTela - MeasureText(line_2, 60))/2, alturaTela/4.5, 60, WHITE);
        DrawText(line_3, (larguraTela - MeasureText(line_3, 60))/2, alturaTela/3, 60, WHITE);
        DrawText(line_4, (larguraTela - MeasureText(line_4, 60))/2, alturaTela/2, 60, GRAY);

    EndDrawing();

    if(IsKeyPressed(KEY_SPACE)){
        boolLoadedGameOver = 0;
        UnloadTexture(textureGameOver);
        *screenSelector = MENU_INICIAL;
        return;
    }

}