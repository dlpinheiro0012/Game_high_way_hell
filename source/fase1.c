#include "fase1.h"

void InitFase_1(Screen* screenSelector){
    const int limite_golpes = 10; //Limite de golpes necessário para derrotar o inimigo
    static int contador_ataques = 0; //Contador de ataques realizados pelo jogador
    static int boolTempoInicial = 0; //Booleano para fazer a verificação: Contador Começou Agora?
    static int boolVenceu = 0; //Booleano para fazer a verificação de vitória
    static int tempoInicial = 0; // Tempo inicial do contador
    static int tempoAtual = 0; // Tempo atual que está passando

    //Se a fase tiver começado(Key_H) e o booleano tiver zerado(não começou), começa a contagem
    if (IsKeyPressed(KEY_H) && boolTempoInicial == 0 && boolVenceu == 0){
        boolTempoInicial = 1;
        tempoInicial = GetTime(); //pega o tempo de começo da contagem
    }

    if (boolTempoInicial == 1){
        tempoAtual = GetTime(); //quando está rodando, ele pega o tempo que está rodando
    }

    BeginDrawing();
        ClearBackground(CorBackGroundFase1);
        DrawRectangle(0, 3*(alturaTela / 4), larguraTela, larguraTela / 4, BLACK);
        DrawRectangle(80, (alturaTela / 8) * 2, 70, 500, GREEN);
        DrawText(TextFormat("Contagem de Ataques: %d", contador_ataques), 600, 600, 30, WHITE);
        DrawText(TextFormat("Contagem de Tempo: %d", 10 - (tempoAtual - tempoInicial)), 600, 650, 30, WHITE);

        if(IsKeyPressed(KEY_D)){ //Toda vez que a tecla D for pressionada, o personagem fará um ataque
            contador_ataques++;
        }

        if(contador_ataques > 0 && contador_ataques <= limite_golpes){ //Quando o contador de ataques for maior do que 0 (ele acertou um ataque)
            DrawRectangle(80, (alturaTela / 8) * 2, 70, contador_ataques * (500 / limite_golpes), BLACK);
        }

        if(contador_ataques == limite_golpes){
            DrawText("VOCÊ VENCEU!!", 600, 400, 60, WHITE);
            boolTempoInicial = 0;
            boolVenceu = 1;
        }

        else if(contador_ataques > limite_golpes){
            *screenSelector = CREDITOS;
            boolVenceu = 0;
            contador_ataques = 0;
            tempoInicial = 0;
            tempoAtual = 0;
        }
        //Faz a verificação se o tempo do contador chegou em 10 e reincia todas as contagens p/ novas tentativas
        else if(tempoAtual - tempoInicial == 10){
            *screenSelector = GAME_OVER;
            boolTempoInicial = 0;
            tempoInicial = 0;
            tempoAtual = 0;
        }
        
        EndDrawing();
}