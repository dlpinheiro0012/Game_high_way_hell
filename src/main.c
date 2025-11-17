#include "raylib.h"
#include "menu.h"
#include "creditos.h"
#include "load_music.h"

int main(void) {
    const int largura_tela = 1920;
    const int altura_tela = 1080;

    InitWindow(largura_tela, altura_tela, "High Way Hell");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        int resultado = init_menu(largura_tela, altura_tela);

        init_music(); //a musica toca indefinidamente, enquanto o jogo estiver rodando (em creditos, jogando ou menu)

        if (resultado == 1) { 
            init_creditos(largura_tela, altura_tela);

        } else if(resultado==2) { //Aqui, tem que gerar o local que o jogo vai rodar mesmo
            break;

        } else { // else, end the game
            break;
        }
    }

    CloseWindow();
    return 0;
}
