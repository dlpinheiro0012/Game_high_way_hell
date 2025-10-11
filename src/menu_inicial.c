#include <stdio.h>
#include "raylib.h"
#include "menu_inicial.h"

void init_menu(){
    BeginDrawing();

        ClearBackground(GRAY);

        DrawText("TESTE MENU INICIAL", 250, 500, 40, GREEN);

    EndDrawing();
}