#include "raylib.h"
#include "menu.h"
#include "creditos.h"
#include "constantes.h"
#include "load.h"
#include "fase1.h"
#include "lore.h"
#include "game_over.h"

int main(void) {
    InitAudioDevice();
    InitWindow(larguraTela, alturaTela, "High Way Hell");
    
    Music musicTheme = musicMenu();

    SetTargetFPS(60);

    Screen screenSelector = MENU_INICIAL; // MENU_INCIAL, CREDITOS, LORE (1,2,3), FASE1;
    
    while (!WindowShouldClose()) {
        Selector Choose[] = {
            InitMenu,
            InitCreditos,
            InitLore,
            InitFase_1,
            InitGameOver
        };

        Choose[screenSelector](&screenSelector);

        SetMusicVolume(musicTheme, 0.1); 
        UpdateMusicStream(musicTheme);
    }

    CloseWindow();
    return 0;
}
