#include <stdio.h>
#include "raylib.h"
#include "creditos.h"

int InitCreditos(int largura_tela, int altura_tela) {
    SetTargetFPS(60);
        BeginDrawing();
            ClearBackground(BLACK);
            // Créditos
            DrawText("Press BACKSPACE to menu", 20, 20, 30, GRAY);
            DrawText("CREDITOS", largura_tela/2.95, altura_tela/7, 120, RED);
            DrawText("Equipe :", largura_tela/6, altura_tela/3, 55, RED);
            DrawText("Arthur Moura Barbosa Vieira <ambv>", largura_tela/3.5, altura_tela/3, 55, WHITE);
            DrawText("Davi José de Santana Barbosa <djsb>", largura_tela/3.5, altura_tela/2.65, 55, WHITE);
            DrawText("Davi Lima Pinheiro <dlp>", largura_tela/3.5, altura_tela/2.38, 55, WHITE);
            DrawText("Gabriel Marins Zarour <gmz>", largura_tela/3.5, altura_tela/2.16, 55, WHITE);
            DrawText("Matheus Silva Vasconcelos <msv5>", largura_tela/3.5, altura_tela/1.98, 55, WHITE);
        EndDrawing();
}
