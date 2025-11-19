#include <stdio.h>
#include "raylib.h"
#include "lore.h"
#include "constantes.h"
#include <string.h>

//função para entrar o texto de forma digitada e não estática
void DrawTextDigitado(const char *texto, int x, int y, int size, Color cor, float velocidade) {
    static float contador = 0;
    contador += velocidade;

    int letras = (int)contador;
    int total = strlen(texto);

    if (letras > total) letras = total;

    char buffer[512];
    strncpy(buffer, texto, letras);
    buffer[letras] = '\0';

    DrawText(buffer, x, y, size, cor);
}


int InitLore(const int larguraTela, const int alturaTela) {
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(BLACK);

    DrawTextDigitado("O Reino de Motorolos entrou em caos quando a princesa", larguraTela/10, alturaTela/7, 30, WHITE,1);
    DrawTextDigitado("Alexandrina foi raptada por Jobos, tirano do inferno da maçã.", larguraTela/10, alturaTela/5.5, 30, WHITE,0.6);

    DrawTextDigitado("Você, um herói imperativo, deve atravessar os dois vales de Cinlândia", larguraTela/10, alturaTela/4, 30, WHITE,0.6);
    DrawTextDigitado("e descer rumo ao recanto de jobos para resgatá-la o mais rápido possivel!.", larguraTela/10, alturaTela/3.5, 30, WHITE,0.6);

    DrawTextDigitado("Primeiro, googlios, um servo inferior, preparou uma barreira", larguraTela/10, alturaTela/2.8, 30, WHITE,0.6);
    DrawTextDigitado("impenetrável... Vença-a e siga HIGH WAY TO HELL!!!", larguraTela/10, alturaTela/2.5, 30, WHITE,0.6);

    DrawTextDigitado("Pressione W para atingir seu inimigo", larguraTela/10, alturaTela/2, 20, RED,0.6);
    DrawTextDigitado("Pressione H para começar", larguraTela/10, alturaTela/1.9, 20, RED,0.6);

    EndDrawing();
}
