#include "raylib.h"

int main(void)
{

    const int screenWidth = 1920;
    const int screenHeight = 1080;
    short int volta_menu = 0;
    
    InitWindow(screenWidth, screenHeight, "Highway To Hell");
    
    SetTargetFPS(60);             

    while (!WindowShouldClose())
    {
        
        if(IsKeyPressed(KEY_BACKSPACE)) volta_menu = 1;
        
        BeginDrawing();

            ClearBackground(BLACK);
            
            DrawText("CREDITOS", screenWidth/2.95, screenHeight/7, 120, RED);
            DrawText("Equipe :", screenWidth/6, screenHeight/3, 55, RED);
            DrawText("Arthur Moura Barbosa Vieira <ambv>", screenWidth/3.5, screenHeight/3, 55, WHITE);
            DrawText("Davi José de Santana Barbosa <djsb>", screenWidth/3.5, screenHeight/2.65, 55, WHITE);
            DrawText("Davi Lima Pinheiro <dlp>", screenWidth/3.5, screenHeight/2.38, 55, WHITE);
            DrawText("Gabriel Marins <>", screenWidth/3.5, screenHeight/2.16, 55, WHITE);
            DrawText("Matheus Silva Vasconcelos <msv5>", screenWidth/3.5, screenHeight/1.98, 55, WHITE);
            
            if(volta_menu == 0) DrawText("BACKSPACE PARA MENU", screenWidth/20, screenHeight/15, 30, BLUE);
            else if(volta_menu == 1) DrawText("MENU", screenWidth/20, screenHeight/15, 30, BLUE);
            

        EndDrawing();

    }

    CloseWindow();     

    return 0;
}