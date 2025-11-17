#include "raylib.h"
#include "menu.h"
#include "creditos.h"
#include "constantes.h"
#include "load.h"

int main(void) {
    InitAudioDevice();
    InitWindow(largura_tela(), altura_tela(), "High Way Hell");
    
    Music musicTheme = music_menu();

    SetTargetFPS(60);
    int resultado = 0;
    while (!WindowShouldClose()) {
        SetMusicVolume(musicTheme, 0.1); 
        UpdateMusicStream(musicTheme);

        if(IsKeyPressed(KEY_C)) resultado = 1;
        else if(IsKeyPressed(KEY_BACKSPACE)) resultado = 0;

        if(resultado == 0)
            init_menu(largura_tela(), altura_tela());
        
        else if (resultado == 1) 
            init_creditos(largura_tela(), altura_tela());
        
        else if(resultado == 2 ) //Aqui, tem que gerar o local que o jogo vai rodar mesmo
            break;
        
        else if(resultado == -1) // else, end the game
            break;
        
    }

    CloseWindow();
    return 0;
}
