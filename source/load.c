#include "load.h"

Music musicMenu(){ 
    Music musicTheme = LoadMusicStream("assets/musicas/hwh_music.mp3");
    if (IsMusicValid(musicTheme)) PlayMusicStream(musicTheme);

    return musicTheme;
}

Music musicFase1(){ 
    Music musicTheme = LoadMusicStream("assets/musicas/hwh_music.mp3");
    if (IsMusicValid(musicTheme)) PlayMusicStream(musicTheme);

    return musicTheme;
}

//Função para digitar o texto suavemente
void DrawTextDigitado(const char *texto, int x, int y, int size, Color cor, float velocidade) {
    static float contador = 0;
    contador += velocidade;

    int letras = (int)contador;
    int total = strlen(texto);

    if (letras > total) letras = total;

    char buffer[512];
    strncpy(buffer, texto, letras);
    buffer[letras] = '\0';

    DrawText(buffer, x, y, size, cor);
}

//Carregamento de qualquer imagem (desde que não seja personagens)
Texture2D LoadAnyTexture(const char* path){
    static Image image;
    static Texture2D texture;
    
    image = LoadImage(path);//carrega a imagem

    if(IsImageValid(image)){
        texture = LoadTextureFromImage(image);//cria a textura da imagem
        UnloadImage(image);//descarrega a imagem
        
        return texture;
    }
}

//Carregamento de personagens
Texture2D LoadPerson(const char* path, float multiplier){
    Image image = LoadImage(path);

    if (IsImageValid(image)){
        int imageWidth = image.width;
        int imageHeight = image.height;

        ImageResizeNN(&image, multiplier * imageWidth, multiplier * imageHeight);
        Texture2D texture = LoadTextureFromImage(image);
        UnloadImage(image);

        return texture;
    }
}