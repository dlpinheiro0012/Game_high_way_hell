#include "raylib.h"
#include "load.h" //PARA FAZER LOAD DE ASSETS: USAR carregar_assets();
#include "menu.h" //PARA INICIAR MENU: USAR init_menu();
#include "creditos.h" //PARA INICIAR CRÉDITOS: USAR init_creditos();

int main(void) {
    const int largura_tela = 1920;
    const int altura_tela = 1080;
    
    InitWindow(largura_tela, altura_tela, "Highway to Hell");
    SetTargetFPS(60);
    carregar_assets();

    while (!WindowShouldClose())
    {
        init_menu();
        //init_creditos();
    }

    CloseWindow();

    return 0;
}
