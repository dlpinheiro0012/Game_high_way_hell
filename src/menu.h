#ifndef MENU_H
#define MENU_H
#include "raylib.h"

typedef enum {
    TELA_MENU,
    TELA_CREDITOS
} TelaAtual;

// Função para desenhar o menu e retornar a próxima tela
TelaAtual AtualizarMenu(void);
#endif
