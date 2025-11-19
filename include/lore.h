#ifndef LORE_H
#define LORE_H
#include "raylib.h"

int InitLore(const int larguraTela, const int alturaTela);

void DrawTextDigitado(const char *texto, int x, int y, int size, Color cor, float velocidade);

#endif