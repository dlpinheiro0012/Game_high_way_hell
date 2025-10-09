#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Meu Jogo no GitHub");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Este projeto veio do GitHub!", 170, 280, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}