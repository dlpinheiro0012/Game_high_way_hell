#include "menu.h"
#include"load.h"

int boolLoaded = 0;//flag para verificar se as imagens foram carregadas

void InitMenu(Screen* screenSelector) {
    static Texture2D texture_menu;
    if(boolLoaded == 0) texture_menu = LoadAnyTexture("assets/imagens/menus_creen.png");
    boolLoaded = 1;
        BeginDrawing();
            DrawTexture(texture_menu, 0, 0, WHITE);
            const char *textoPlay = "Press SPACE to play";
            const char *textoCreditos = "Press C to credits";
            DrawText(textoPlay, (larguraTela - MeasureText(textoPlay, 30))/2, alturaTela/2, 30, GRAY);
            DrawText(textoCreditos, (larguraTela - MeasureText(textoCreditos, 30))/2, alturaTela/1.8, 30, GRAY);
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)){
            UnloadTexture(texture_menu);
            boolLoaded = 0;
            *screenSelector = LORE1;
        }
        if (IsKeyPressed(KEY_C)){
            UnloadTexture(texture_menu);
            boolLoaded = 0;
            *screenSelector = CREDITOS;
        }
}
