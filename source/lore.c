#include <stdio.h>
#include "raylib.h"
#include "lore.h"
#include "constantes.h"

int InitLore(const int larguraTela, const int alturaTela) {
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(BLACK);

            DrawText("Caminho p/ Lore funcionando", larguraTela/2.95, alturaTela/7, 55, WHITE);
            DrawText("Pressione h para ir para a fase1", larguraTela/6, alturaTela/3, 55, RED);

    EndDrawing();

}