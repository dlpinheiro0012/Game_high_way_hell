#include "raylib.h"
#include "menu.h"
#include "creditos.h"

int main(void) {
    const int largura_tela = 1920;
    const int altura_tela = 1080;

    InitWindow(largura_tela, altura_tela, "High Way Hell");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        int resultado = init_menu(largura_tela, altura_tela);

        if (resultado == 1) {
            init_creditos(largura_tela, altura_tela);
        } else {
            break;
        }
    }

    CloseWindow();
    return 0;
}
