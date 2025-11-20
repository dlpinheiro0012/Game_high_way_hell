#include "menu.h"

void InitMenu(Screen* screenSelector) {
        BeginDrawing();
            ClearBackground(BLACK);

            const char *titulo = "HighWay to Hell!!!";
            int tamanhoTitulo = 50;
            int larguraTitulo = MeasureText(titulo, tamanhoTitulo);
            DrawText(titulo, (larguraTela - larguraTitulo)/2, alturaTela/4, tamanhoTitulo, RAYWHITE);

            const char *textoPlay = "Press SPACE to play";
            const char *textoCreditos = "Press C to credits";
            DrawText(textoPlay, (larguraTela - MeasureText(textoPlay, 30))/2, alturaTela/2, 30, GRAY);
            DrawText(textoCreditos, (larguraTela - MeasureText(textoCreditos, 30))/2, alturaTela/1.8, 30, GRAY);
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE))
            *screenSelector = LORE1;

        if (IsKeyPressed(KEY_C))
            *screenSelector = CREDITOS;
}
