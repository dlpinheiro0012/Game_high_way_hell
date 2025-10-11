#include <stdio.h>
#include "raylib.h"
#include "creditos.h"

void init_creditos(){
    BeginDrawing();

        ClearBackground(GRAY);

        DrawText("TESTE CREDITOS", 250, 500, 40, GREEN);

    EndDrawing();
}