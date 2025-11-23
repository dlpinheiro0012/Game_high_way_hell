#include "game_over.h"

void InitGameOver(Screen *screenSelector){
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(BLACK);

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
        *screenSelector = MENU_INICIAL;
    }

}