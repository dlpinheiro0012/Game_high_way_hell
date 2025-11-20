#include "constantes.h"
#include "raylib.h"

int larguraTela = 1920;

int alturaTela = 1080;

void InitConfigTela(){
    int monitor = GetCurrentMonitor();
    larguraTela = GetMonitorWidth(monitor);
    alturaTela = GetMonitorHeight(monitor);
}

const Color CorBackGroundFase1 = {173, 0, 30, 200};