#include "fase1.h"
#include "load.h"

void InitFase_1(Screen* screenSelector){
    const int limite_golpes = 100; //Limite de golpes necessário para derrotar o inimigo - PRECISA SER MÚLTIPLO DE 500!
    static int contadorAtaques = 0; //Contador de ataques realizados pelo jogador
    
    static int boolTempoInicial = 0; //Booleano para fazer a verificação: Contador Começou Agora?
    static int boolVenceu = 0; //Booleano para fazer a verificação de vitória
    static int boolAnimacao = 0;
    
    static int tempoInicial = 0; // Tempo inicial do contador
    static int tempoAtual = 0; // Tempo atual que está passando
    static float tempoAnimacao = 0.25;
    
    static Texture2D textureBackground;//Textura para o background
    static Texture2D textureGround;//Textura para o chão
    
    static Person Enemy;//Textura para o inimigo
    static Person mainCharacter;//Textura para o protagonista
    
    //Se a fase tiver começado(Key_H) e o booleano tiver zerado(não começou), começa a contagem
    if (IsKeyPressed(KEY_H) && boolTempoInicial == 0 && boolVenceu == 0){
        boolTempoInicial = 1;
        tempoInicial = GetTime(); //pega o tempo de começo da contagem
        
        //Carregamento das texturas de background e chão
        textureBackground = LoadAnyTexture("assets/imagens/background_inferno_1.png");
        textureGround = LoadAnyTexture("assets/imagens/ground.jpg");
        
        //Carregamento de texturas de personagens
        Enemy.stand = LoadPerson("assets/imagens/demon_stand.png", 3);
        Enemy.fight = LoadPerson("assets/imagens/demon_suffer.png", 6);
        mainCharacter.stand = LoadPerson("assets/imagens/main_character_standing.png", 1.25);
        mainCharacter.fight = LoadPerson("assets/imagens/main_character_fighting.png", 2);
    }

    if (boolTempoInicial == 1){
        tempoAtual = GetTime(); //quando está rodando, ele pega o tempo que está rodando
    }

    BeginDrawing();
        DrawTexture(textureBackground, 0, 0, WHITE);// desenha a textura do background
        DrawTexture(textureGround, 0, 810, WHITE);// desenha a textura do chão
        DrawRectangle(7 * larguraTela / 8, (alturaTela / 8) * 2, 70, 500, GREEN);

        DrawText(TextFormat("Tempo: %d", 20 - (tempoAtual - tempoInicial)), 4 * (larguraTela / 9), alturaTela / 8, 45, WHITE); //Mostra quanto tempo falta para o jogador

        if(!IsKeyPressed(KEY_D) && boolAnimacao == 0){ //Toda vez que a tecla D for pressionada, o personagem fará um ataque
            DrawTexture(mainCharacter.stand, 2 * (larguraTela / 8), (alturaTela / 1.75), WHITE); //Textura do protagonista parado
            DrawTexture(Enemy.stand ,(larguraTela / 4), (alturaTela / 64), WHITE);
        }

        else{
            if (IsKeyPressed(KEY_D))
                contadorAtaques++;
            
            boolAnimacao = 1;

            if (boolAnimacao == 1){
                tempoAnimacao -= GetFrameTime();
                DrawTexture(mainCharacter.fight, 2 * (larguraTela / 8), (alturaTela / 1.75), WHITE); //Textura do protagonista lutando
                DrawTexture(Enemy.fight, (larguraTela / 4), (alturaTela / 64), WHITE); //Textura do inimigo sofrendo hit

                if (tempoAnimacao <= 0){
                    boolAnimacao = 0;
                    tempoAnimacao = 0.25;
                }
            }
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
            //Descarregamento da textura do chão e do background
            UnloadTexture(textureBackground);
            UnloadTexture(textureGround);
            
            //Descarregamento das texturas dos personagens
            UnloadTexture(Enemy.stand);
            UnloadTexture(Enemy.fight);
            UnloadTexture(mainCharacter.stand);
            UnloadTexture(mainCharacter.fight);
            
            //Seleção da tela de menu
            *screenSelector = CREDITOS;
            
            //Reset de variáveis
            boolVenceu = 0;
            contadorAtaques = 0;
            tempoInicial = 0;
            tempoAtual = 0;
        }
        
        //Faz a verificação se o tempo do contador chegou em 20 e reincia todas as contagens p/ novas tentativas
        else if(tempoAtual - tempoInicial == 20){
            //Descarregamento da textura do chão e do background
            UnloadTexture(textureBackground);
            UnloadTexture(textureGround);
            
            //Descarregamento das texturas dos personagens
            UnloadTexture(Enemy.stand);
            UnloadTexture(Enemy.fight);
            UnloadTexture(mainCharacter.stand);
            UnloadTexture(mainCharacter.fight);
            
            //Selecão da tela de game over
            *screenSelector = GAME_OVER;
            
            //Reset de variáveis
            boolTempoInicial = 0;
            contadorAtaques = 0;
            tempoInicial = 0;
            tempoAtual = 0;
        }
        
        EndDrawing();
}
