#ifndef LORE_H
#define LORE_H
#include <stdio.h>
#include "raylib.h"
#include "constantes.h"
#include "load.h"
#include <string.h>

int InitLore(Screen* screenSelector);

void DrawTextDigitado(const char *texto, int x, int y, int size, Color cor, float velocidade);

#endif