#include "fase1.h"
#include "load.h"

void InitFase_1(Screen* screenSelector){
    const int limite_golpes = 50; //Limite de golpes necessário para derrotar o inimigo - PRECISA SER MÚLTIPLO DE 500!
    static int contador_ataques = 0; //Contador de ataques realizados pelo jogador
    static int boolTempoInicial = 0; //Booleano para fazer a verificação: Contador Começou Agora?
    static int boolVenceu = 0; //Booleano para fazer a verificação de vitória
    static int tempoInicial = 0; // Tempo inicial do contador
    static int tempoAtual = 0; // Tempo atual que está passando
    static Texture2D texture_bg;//Textura para o background
    static Texture2D texture_ground;//Textura para o chão
    //static Texture2D texture_player;//Textura para o player
    static Texture2D texture_enemy;//Textura para o inimigo
    //Se a fase tiver começado(Key_H) e o booleano tiver zerado(não começou), começa a contagem
    if (IsKeyPressed(KEY_H) && boolTempoInicial == 0 && boolVenceu == 0){
        texture_bg = LoadAnyTexture("assets/imagens/background_inferno_1.png");
        texture_ground = LoadAnyTexture("assets/imagens/ground.jpg");
        //texture_player = LoadAnyTexture("assets/imagens/background_inferno_1.png");
        texture_enemy = LoadAnyTexture("assets/imagens/demon_idle_1.png");
        boolTempoInicial = 1;
        tempoInicial = GetTime(); //pega o tempo de começo da contagem
    }

    if (boolTempoInicial == 1){
        tempoAtual = GetTime(); //quando está rodando, ele pega o tempo que está rodando
    }

    BeginDrawing();
        DrawTexture(texture_bg, 0, 0, WHITE);// desenha a textura do background
        DrawTexture(texture_ground, 0, 810, WHITE);// desenha a textura do chão
        DrawRectangle(80, (alturaTela / 8) * 2, 70, 500, GREEN);
        DrawText(TextFormat("Contagem de Ataques: %d", contador_ataques), (larguraTela / 2) - 150, 400, 30, WHITE);
        DrawText(TextFormat("Contagem de Tempo: %d", 20 - (tempoAtual - tempoInicial)), (larguraTela / 2) - 150, 450, 30, WHITE);

        DrawRectangle((larguraTela / 2) - 300, (alturaTela / 1.5), 40, 90, BLUE); //Retângulo do jogador
        DrawTexture(texture_enemy ,(larguraTela / 2) + 300, (alturaTela / 1.64), WHITE); //Retângulo do inimigo

        if(IsKeyPressed(KEY_D)){ //Toda vez que a tecla D for pressionada, o personagem fará um ataque
            contador_ataques++;
        }

        if(contador_ataques > 0 && contador_ataques <= limite_golpes){ //Quando o contador de ataques for maior do que 0 (ele acertou um ataque)
            DrawRectangle(80, (alturaTela / 8) * 2, 70, contador_ataques * (500 / limite_golpes), BLACK);
        }

        if(contador_ataques == limite_golpes){
            DrawText("VOCÊ VENCEU!!", 600, 200, 60, WHITE);
            boolTempoInicial = 0;
            boolVenceu = 1;
        }

        else if(contador_ataques > limite_golpes){
            UnloadTexture(texture_bg);
            UnloadTexture(texture_ground);
            UnloadTexture(texture_enemy);
            *screenSelector = CREDITOS;
            boolVenceu = 0;
            contador_ataques = 0;
            tempoInicial = 0;
            tempoAtual = 0;
        }
        //Faz a verificação se o tempo do contador chegou em 10 e reincia todas as contagens p/ novas tentativas
        else if(tempoAtual - tempoInicial == 20){
            UnloadTexture(texture_bg);
            UnloadTexture(texture_ground);
            UnloadTexture(texture_enemy);
            *screenSelector = GAME_OVER;
            boolTempoInicial = 0;
            tempoInicial = 0;
            tempoAtual = 0;
        }
        
        EndDrawing();
}
