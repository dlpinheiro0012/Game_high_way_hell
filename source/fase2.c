#include "fase2.h"

void InitFase_2(Screen* screenSelector){
    const int limite_golpes_2 = 100; //Limite de golpes necessário para derrotar o inimigo - PRECISA SER MÚLTIPLO DE 500!
    static int contadorAtaques_2 = 0; //Contador de ataques realizados pelo jogador
    
    static int boolTempoInicial_2_2 = 0; //Booleano para fazer a verificação: Contador Começou Agora?
    static int boolVenceu_2 = 0; //Booleano para fazer a verificação de vitória
    static int boolAnimacao_2 = 0;
    
    static int tempoInicial_2 = 0; // Tempo inicial do contador
    static int tempoAtual_2 = 0; // Tempo atual que está passando
    static float tempoAnimacao_2 = 0.25;
    
    static Texture2D textureBackground_2;//Textura para o background
    static Texture2D textureGround_2;//Textura para o chão
    
    static Person_2 Enemy_2;//Textura para o inimigo
    static Person_2 mainCharacter_2;//Textura para o protagonista
    
    //Se a fase tiver começado e o booleano tiver zerado(não começou), começa a contagem
    if (boolTempoInicial_2_2 == 0 && boolVenceu_2 == 0){
        boolTempoInicial_2_2 = 1;
        tempoInicial_2 = GetTime(); //pega o tempo de começo da contagem
         //Carregamento das texturas de background e chão
        textureBackground_2 = LoadAnyTexture("assets/imagens/background_castle.png");
        textureGround_2 = LoadAnyTexture("assets/imagens/ground.jpg");
        
        //Carregamento de texturas de personagens
        Enemy_2.stand_2 = LoadPerson("assets/imagens/demon_king.png", 0.45);
        Enemy_2.fight_2 = LoadPerson("assets/imagens/demon_king_takehit.png", 0.55);
        mainCharacter_2.stand_2 = LoadPerson("assets/imagens/main_character_standing.png", 1.25);
        mainCharacter_2.fight_2 = LoadPerson("assets/imagens/main_character_fighting.png", 2);
    }

    if (boolTempoInicial_2_2 == 1){
        tempoAtual_2 = GetTime(); //quando está rodando, ele pega o tempo que está rodando
    }

    BeginDrawing();
        DrawTexture(textureBackground_2, -200, 0, WHITE);// desenha a textura do background
        DrawTexture(textureGround_2, 0, 810, WHITE);// desenha a textura do chão
        DrawRectangle(7 * larguraTela / 8, (alturaTela / 8) * 2, 70, 500, GREEN);

        DrawText(TextFormat("Tempo: %d", 20 - (tempoAtual_2 - tempoInicial_2)), 4 * (larguraTela / 9), alturaTela / 8, 45, WHITE); //Mostra quanto tempo falta para o jogador

        if(!IsKeyPressed(KEY_D) && boolAnimacao_2 == 0){ //Toda vez que a tecla D for pressionada, o personagem fará um ataque
            DrawTexture(mainCharacter_2.stand_2, 1 * (larguraTela / 8), (alturaTela / 1.75), WHITE); //Textura do protagonista parado
            DrawTexture(Enemy_2.stand_2 ,(larguraTela / 4), (alturaTela / 8), WHITE);
        }

        else{
            if (IsKeyPressed(KEY_D))
                contadorAtaques_2++;
            
            boolAnimacao_2 = 1;

            if (boolAnimacao_2 == 1){
                tempoAnimacao_2 -= GetFrameTime();
                DrawTexture(mainCharacter_2.fight_2, 2 * (larguraTela / 8), (alturaTela / 1.75), WHITE); //Textura do protagonista lutando
                DrawTexture(Enemy_2.fight_2, (larguraTela / 4), (alturaTela / 8), WHITE); //Textura do inimigo sofrendo hit

                if (tempoAnimacao_2 <= 0){
                    boolAnimacao_2 = 0;
                    tempoAnimacao_2 = 0.25;
                }
            }
        }

        if(contadorAtaques_2 > 0 && contadorAtaques_2 <= limite_golpes_2){ //Quando o contador de ataques for maior do que 0 (ele acertou um ataque)
            DrawRectangle(7 * larguraTela / 8, (alturaTela / 8) * 2, 70, contadorAtaques_2 * (500 / limite_golpes_2), BLACK);
        }

        if(contadorAtaques_2 == limite_golpes_2){
            DrawText("VOCÊ VENCEU!!", 600, 200, 60, WHITE);
            boolTempoInicial_2_2 = 0;
            boolVenceu_2 = 1;
            //Descarregamento da textura do chão e do background
            UnloadTexture(textureBackground_2);
            UnloadTexture(textureGround_2);
            
            //Descarregamento das texturas dos personagens
            UnloadTexture(Enemy_2.stand_2);
            UnloadTexture(Enemy_2.fight_2);
            UnloadTexture(mainCharacter_2.stand_2);
            UnloadTexture(mainCharacter_2.fight_2); 

            *screenSelector = CREDITOS;
        }

        else if(contadorAtaques_2 > limite_golpes_2){
            //Descarregamento da textura do chão e do background
            UnloadTexture(textureBackground_2);
            UnloadTexture(textureGround_2);
            
            //Descarregamento das texturas dos personagens
            UnloadTexture(Enemy_2.stand_2);
            UnloadTexture(Enemy_2.fight_2);
            UnloadTexture(mainCharacter_2.stand_2);
            UnloadTexture(mainCharacter_2.fight_2);
            
            //Seleção da tela de menu
            *screenSelector = CREDITOS;
            
            //Reset de variáveis
            boolVenceu_2 = 0;
            contadorAtaques_2 = 0;
            tempoInicial_2 = 0;
            tempoAtual_2 = 0;
        }
        
        //Faz a verificação se o tempo do contador chegou em 20 e reincia todas as contagens p/ novas tentativas
        else if(tempoAtual_2 - tempoInicial_2 == 20){
            //Descarregamento da textura do chão e do background
            UnloadTexture(textureBackground_2);
            UnloadTexture(textureGround_2);
            
            //Descarregamento das texturas dos personagens
            UnloadTexture(Enemy_2.stand_2);
            UnloadTexture(Enemy_2.fight_2);
            UnloadTexture(mainCharacter_2.stand_2);
            UnloadTexture(mainCharacter_2.fight_2);
            
            //Selecão da tela de game over
            *screenSelector = GAME_OVER;
            
            //Reset de variáveis
            boolTempoInicial_2_2 = 0;
            contadorAtaques_2 = 0;
            tempoInicial_2 = 0;
            tempoAtual_2 = 0;
        }
        
        EndDrawing();
}
