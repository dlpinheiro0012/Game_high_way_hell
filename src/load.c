#include "raylib.h"
#include "load.h"
#include <stdio.h>

void carregar_imagens(){
    Image icon = LoadImage("assets/icon.png");
    SetWindowIcon(icon);
}