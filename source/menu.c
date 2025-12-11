#include "menu.h"

int boolLoadedMenu = 0;// Flag para verificar se as imagens foram carregadas

void InitMenu(Screen* screenSelector) {
    static Texture2D textureMenu;
    
    if(boolLoadedMenu == 0) {
        textureMenu = LoadAnyTexture("assets/imagens/menu_inicial.png");
        boolLoadedMenu = 1;
    }
        BeginDrawing();
            DrawTexture(textureMenu, 0, 0, WHITE);
            
            const char *textoPlay = "Press SPACE to play";
            const char *textoCreditos = "Press C to credits";
            
            DrawTextDigitado(textoPlay, (larguraTela - MeasureText(textoPlay, 60))/2, 3 * (alturaTela/4), 60, WHITE, 0.6);
            DrawTextDigitado(textoCreditos, (larguraTela - MeasureText(textoCreditos, 60))/2, 3 * (alturaTela/3.6), 60, WHITE, 0.6);
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)){
            UnloadTexture(textureMenu);
            boolLoadedMenu = 0;
            *screenSelector = LORE1;
            return;
        }
        if (IsKeyPressed(KEY_C)){
            UnloadTexture(textureMenu);
            boolLoadedMenu = 0;
            *screenSelector = CREDITOS;
            return;
        }
}
