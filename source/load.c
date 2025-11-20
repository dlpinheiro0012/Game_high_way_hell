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