#ifndef MENU_H
#define MENU_H

#include "raylib.h"

// Estrutura para armazenar o fundo do menu
typedef struct {
    Texture2D background;
} Menu;

// Inicializa o menu (carrega imagem de fundo)
void InitMenu(Menu *menu);

// Atualiza e desenha o menu (loop principal do menu)
void DrawMenu(Menu *menu);

// Libera recursos do menu (descarrega textura)
void UnloadMenu(Menu *menu);

#endif
