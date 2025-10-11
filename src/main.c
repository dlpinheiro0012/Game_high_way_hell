#include "raylib.h"
#include "load.h"
#include "menu_inicial.h"
#include "creditos.h"

int main(void) {
    const int largura_tela = 1920;
    const int altura_tela = 1080;
    
    InitWindow(largura_tela, altura_tela, "Highway to Hell");
    SetTargetFPS(60);
    carregar_imagens();

    while (!WindowShouldClose())
    {
        //init_menu();
        init_creditos();
    }

    CloseWindow();

    return 0;
}