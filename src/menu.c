#include "raylib.h"
#include "menu.h"

int init_menu(const int largura_tela, const int altura_tela) {
    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground(BLACK);

            const char *titulo = "Prepare-se para jogar!";
            int tamanhoTitulo = 50;
            int larguraTitulo = MeasureText(titulo, tamanhoTitulo);
            DrawText(titulo, (largura_tela - larguraTitulo)/2, altura_tela/4, tamanhoTitulo, RAYWHITE);

            const char *textoPlay = "Press SPACE to play";
            const char *textoCreditos = "Press C to credits";
            DrawText(textoPlay, (largura_tela - MeasureText(textoPlay, 30))/2, altura_tela/2, 30, GRAY);
            DrawText(textoCreditos, (largura_tela - MeasureText(textoCreditos, 30))/2, altura_tela/1.8, 30, GRAY);

        EndDrawing();
        // Se o jogador pressionar C → vai para créditos
        if (IsKeyPressed(KEY_C)) {
            return 1;
        }
        // Se pressionar ESC → fecha o jogo
        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
    }
    return 0;
}
