#include "menu.h"

TelaAtual AtualizarMenu(void) {
    BeginDrawing();
        ClearBackground(BLACK);

        // Gerando o texto de título
        const char *titulo = "Prepare-se para jogar!";
        int fontSizeTitulo = 40;
        int textWidthTitulo = MeasureText(titulo, fontSizeTitulo);
        DrawText(titulo, (GetScreenWidth() - textWidthTitulo)/2, 150, fontSizeTitulo, RAYWHITE);

        // Gerando as opções de lógica (agr apenas pra créditos)
        const char *op1 = "Press SPACE to Play";
        const char *op2 = "Press C to Credits";
        int fontSizeOp = 20;

        DrawText(op1, (GetScreenWidth() - MeasureText(op1, fontSizeOp))/2, 250, fontSizeOp, GRAY);
        DrawText(op2, (GetScreenWidth() - MeasureText(op2, fontSizeOp))/2, 280, fontSizeOp, GRAY);

    EndDrawing();

    // Lógica de navegação
    if (IsKeyPressed(KEY_C)) return TELA_CREDITOS;
    else return TELA_MENU;
}
