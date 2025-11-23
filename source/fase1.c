#include "fase1.h"
#include "load.h"

void InitFase_1(Screen* screenSelector){
    const int limite_golpes = 100; //Limite de golpes necessário para derrotar o inimigo - PRECISA SER MÚLTIPLO DE 500!
    static int contadorAtaques = 0; //Contador de ataques realizados pelo jogador
    
    static int boolTempoInicial = 0; //Booleano para fazer a verificação: Contador Começou Agora?
    static int boolVenceu = 0; //Booleano para fazer a verificação de vitória
    
    static int tempoInicial = 0; // Tempo inicial do contador
    static int tempoAtual = 0; // Tempo atual que está passando
    
    static Texture2D texture_bg;//Textura para o background
    static Texture2D texture_ground;//Textura para o chão
    static Texture2D texture_enemy;//Textura para o inimigo
    static Texture2D texture_main_character;//Textura para o protagonista
    
    //Se a fase tiver começado(Key_H) e o booleano tiver zerado(não começou), começa a contagem
    if (IsKeyPressed(KEY_H) && boolTempoInicial == 0 && boolVenceu == 0){
        boolTempoInicial = 1;
        tempoInicial = GetTime(); //pega o tempo de começo da contagem
        
        //Carregamento das texturas de background, chão, inimigo e protagonista
        texture_bg = LoadAnyTexture("assets/imagens/background_inferno_1.png");
        texture_ground = LoadAnyTexture("assets/imagens/ground.jpg");
        texture_enemy = LoadPerson("assets/imagens/demon_idle_1.png", 3);
        texture_main_character = LoadPerson("assets/imagens/main_character_1.png", 2);
    }

    if (boolTempoInicial == 1){
        tempoAtual = GetTime(); //quando está rodando, ele pega o tempo que está rodando
    }

    BeginDrawing();
        DrawTexture(texture_bg, 0, 0, WHITE);// desenha a textura do background
        DrawTexture(texture_ground, 0, 810, WHITE);// desenha a textura do chão
        DrawRectangle(7 * larguraTela / 8, (alturaTela / 8) * 2, 70, 500, GREEN);

        DrawText(TextFormat("Tempo: %d", 20 - (tempoAtual - tempoInicial)), 4 * (larguraTela / 9), alturaTela / 8, 45, WHITE); //Mostra quanto tempo falta para o jogador

        DrawTexture(texture_main_character, 2 * (larguraTela / 8), (alturaTela / 2), WHITE); //Retângulo do jogador
        DrawTexture(texture_enemy ,(larguraTela / 4), (alturaTela / 16), WHITE); //Retângulo do inimigo

        if(IsKeyPressed(KEY_D)){ //Toda vez que a tecla D for pressionada, o personagem fará um ataque
            contadorAtaques++;
        }

        if(contadorAtaques > 0 && contadorAtaques <= limite_golpes){ //Quando o contador de ataques for maior do que 0 (ele acertou um ataque)
            DrawRectangle(7 * larguraTela / 8, (alturaTela / 8) * 2, 70, contadorAtaques * (500 / limite_golpes), BLACK);
        }

        if(contadorAtaques == limite_golpes){
            DrawText("VOCÊ VENCEU!!", 600, 200, 60, WHITE);
            boolTempoInicial = 0;
            boolVenceu = 1;
        }

        else if(contadorAtaques > limite_golpes){
            UnloadTexture(texture_bg);
            UnloadTexture(texture_ground);
            UnloadTexture(texture_enemy);
            
            *screenSelector = CREDITOS;
            
            boolVenceu = 0;
            contadorAtaques = 0;
            tempoInicial = 0;
            tempoAtual = 0;
        }
        
        //Faz a verificação se o tempo do contador chegou em 20 e reincia todas as contagens p/ novas tentativas
        else if(tempoAtual - tempoInicial == 20){
            UnloadTexture(texture_bg);
            UnloadTexture(texture_ground);
            UnloadTexture(texture_enemy);
            UnloadTexture(texture_main_character);
            
            *screenSelector = GAME_OVER;
            
            boolTempoInicial = 0;
            contadorAtaques = 0;
            tempoInicial = 0;
            tempoAtual = 0;
        }
        
        EndDrawing();
}
