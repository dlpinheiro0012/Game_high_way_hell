#ifndef INTERLUDIO_H
#define INTERLUDIO_H
#include <stdio.h>
#include "raylib.h"
#include "constantes.h"
#include "load.h"
#include <string.h>

void InitInterludio(Screen* screenSelector);

void DrawTextDigitado(const char *texto, int x, int y, int size, Color cor, float velocidade);

#endif