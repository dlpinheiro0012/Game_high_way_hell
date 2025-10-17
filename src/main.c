#include "raylib.h"
#include "load.h" //PARA FAZER LOAD DE ASSETS: USAR carregar_assets();
#include "menu_inicial.h" //PARA INICIAR MENU: USAR init_menu();
#include "creditos.h" //PARA INICIAR CRÉDITOS: USAR init_creditos();

int main(void) {
    int volta_menu = 0;
    const int largura_tela = 1920;
    const int altura_tela = 1080;
    
    InitWindow(largura_tela, altura_tela, "Highway to Hell");
    SetTargetFPS(60);
    carregar_assets();

    while (!WindowShouldClose())
    {
        if(IsKeyDown(KEY_BACKSPACE)) volta_menu = 1;
        
        if(volta_menu == 0) init_menu();
        else if(volta_menu == 1)init_creditos(largura_tela, altura_tela);
        
        if(IsKeyDown(KEY_ENTER)) volta_menu = 0;
    }

    CloseWindow();

    return 0;
}