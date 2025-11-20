#include "creditos.h"

int InitCreditos(Screen* screenSelector) {
    SetTargetFPS(60);
        BeginDrawing();
            ClearBackground(BLACK);
            // Créditos
            DrawText("Press BACKSPACE to menu", 20, 20, 30, GRAY);
            DrawText("CREDITOS", larguraTela/2.95, alturaTela/7, 120, RED);
            DrawText("Equipe :", larguraTela/6, alturaTela/3, 55, RED);
            DrawText("Arthur Moura Barbosa Vieira <ambv>", larguraTela/3.5, alturaTela/3, 55, WHITE);
            DrawText("Davi José de Santana Barbosa <djsb>", larguraTela/3.5, alturaTela/2.65, 55, WHITE);
            DrawText("Davi Lima Pinheiro <dlp>", larguraTela/3.5, alturaTela/2.38, 55, WHITE);
            DrawText("Gabriel Marins Zarour <gmz>", larguraTela/3.5, alturaTela/2.16, 55, WHITE);
            DrawText("Matheus Silva Vasconcelos <msv5>", larguraTela/3.5, alturaTela/1.98, 55, WHITE);
        EndDrawing();

    if (IsKeyPressed(KEY_BACKSPACE))
        *screenSelector = MENU_INICIAL;
}
