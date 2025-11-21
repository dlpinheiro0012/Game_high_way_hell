#include "game_over.h"

void InitGameOver(Screen *screenSelector){
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("O guerreiro infelizmente cedeu, e", larguraTela/10, alturaTela/7, 30, WHITE);
    DrawText("agora a tirania da maçã continuará a reinar.", larguraTela/10, alturaTela/5.5, 30, WHITE);
    DrawText("O mundo está perdido...", larguraTela/10, alturaTela/4, 30, WHITE);

    DrawText("Pressione espaço para voltar ao menu", larguraTela/10, alturaTela/2.8, 30, WHITE);

    EndDrawing();

    if(IsKeyPressed(KEY_SPACE)){
        *screenSelector = MENU_INICIAL;
    }

}