#include "load.h"

Music musicMenu(){ 
    Music musicTheme = LoadMusicStream("assets/musicas/hwh_music.mp3");
    if (IsMusicValid(musicTheme)) PlayMusicStream(musicTheme);

    return musicTheme;
}

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

Texture2D LoadAnyTexture(const char* path){
    static Image image;
    static Texture2D texture;
    image = LoadImage(path);//carrega a imagem 
    texture = LoadTextureFromImage(image);//cria a textura da imagem
    UnloadImage(image);//descarrega a imagem

    return texture;
}

Texture2D LoadPerson(const char* path){
    Image image = LoadImage(path);
    int imageWidth = image.width;
    int imageHeight = image.height;

    ImageResizeNN(&image, 3 * imageWidth, 3 * imageHeight);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    return texture;
}