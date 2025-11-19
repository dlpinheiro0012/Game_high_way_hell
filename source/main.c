#include "raylib.h"
#include "menu.h"
#include "creditos.h"
#include "constantes.h"
#include "load.h"
#include "fase1.h"
#include "lore.h"

int main(void) {
    InitAudioDevice();
    InitWindow(larguraTela, alturaTela, "High Way Hell");
    
    Music musicTheme = musicMenu();

    SetTargetFPS(60);

    Screen screenSelector = MENU_INICIAL; // MENU_INCIAL, CREDITOS, LORE (1,2,3), FASE1;
    
    while (!WindowShouldClose()) {
        SetMusicVolume(musicTheme, 0.1); 
        UpdateMusicStream(musicTheme);
        
        if(screenSelector == MENU_INICIAL){
            InitMenu(larguraTela, alturaTela);
            
            if(IsKeyPressed(KEY_C)) 
            screenSelector = CREDITOS;
            
            if (IsKeyPressed(KEY_SPACE))
            screenSelector = LORE1;
        }
        
        else if (screenSelector == CREDITOS){ 
            InitCreditos(larguraTela, alturaTela);
            
            if(IsKeyPressed(KEY_BACKSPACE)) 
            screenSelector = 0;

        }

        else if (screenSelector == LORE1) {
            InitLore(larguraTela, alturaTela);

            if (IsKeyPressed(KEY_H))
            screenSelector = FASE1;

        }
        else if(screenSelector == FASE1) // Seleciona a fase 1
            InitFase_1(larguraTela, alturaTela);
        
        else if(screenSelector == -1) // else, end the game
            break;
        
    }

    CloseWindow();
    return 0;
}
