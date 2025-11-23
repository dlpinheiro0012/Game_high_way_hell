#include "menu.h"

int boolLoaded = 0;// Flag para verificar se as imagens foram carregadas

void InitMenu(Screen* screenSelector) {
    static Texture2D texture_menu;
    if(boolLoaded == 0) {
        texture_menu = LoadAnyTexture("assets/imagens/menu_inicial.png");
        boolLoaded = 1;
    }
        BeginDrawing();
            DrawTexture(texture_menu, 0, 0, WHITE);
            
            const char *textoPlay = "Press SPACE to play";
            const char *textoCreditos = "Press C to credits";
            
            DrawTextDigitado(textoPlay, (larguraTela - MeasureText(textoPlay, 60))/2, 3 * (alturaTela/4), 60, WHITE, 0.6);
            DrawTextDigitado(textoCreditos, (larguraTela - MeasureText(textoCreditos, 60))/2, 3 * (alturaTela/3.6), 60, WHITE, 0.6);
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
