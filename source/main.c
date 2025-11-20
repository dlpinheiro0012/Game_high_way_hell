#include "raylib.h"
#include "menu.h"
#include "creditos.h"
#include "constantes.h"
#include "load.h"
#include "fase1.h"
#include "lore.h"
#include "game_over.h"

int main(void) {
    InitAudioDevice(); // Inicialização do gerenciador de áudio;
    InitWindow(larguraTela, alturaTela, "High Way Hell"); // Inicialização da tela;
    
    Music musicTheme = musicMenu();

    SetTargetFPS(60);

    Screen screenSelector = MENU_INICIAL; // MENU_INCIAL(1), CREDITOS(2), LORE (3), FASE1(4), GAME_OVER(5);
    
    while (!WindowShouldClose()) {
        SetMusicVolume(musicTheme, 0.1); 
        UpdateMusicStream(musicTheme);
        
        Selector Choose[] = { // Ponteiro de funções para reduzir o número de if-else;
            InitMenu,
            InitCreditos,
            InitLore,
            InitFase_1,
            InitGameOver
        };

        Choose[screenSelector](&screenSelector); // Seleção dentro do ponteiro de funções;
    }

    CloseWindow();
    return 0;
}
