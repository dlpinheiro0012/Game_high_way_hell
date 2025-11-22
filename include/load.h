#ifndef LOAD_H
#define LOAD_H
#include "raylib.h"
#include <stdio.h>
#include <string.h>

Music musicMenu();

void DrawTextDigitado(const char *texto, int x, int y, int size, Color cor, float velocidade);

Texture2D LoadAnyTexture(const char* path);

#endif 