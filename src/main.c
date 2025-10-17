#include "raylib.h"
#include "menu.h"
#include "creditos.h"

int main(void) {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "High Way Hell");
    SetTargetFPS(60);

    TelaAtual tela = TELA_MENU;

    while (!WindowShouldClose()) {
        switch (tela) {
            case TELA_MENU:
                tela = AtualizarMenu();
                break;

            case TELA_CREDITOS:
                AtualizarCreditos();
                if (IsKeyPressed(KEY_ESCAPE)) tela = TELA_MENU;
                break;
        }
    }

    CloseWindow();
    return 0;
}
