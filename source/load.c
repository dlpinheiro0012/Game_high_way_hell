#include "raylib.h"
#include "load.h"
#include <stdio.h>

Music musicMenu(){ 
    Music musicTheme = LoadMusicStream("assets/musicas/hwh_music.mp3");
    if (IsMusicValid(musicTheme)) PlayMusicStream(musicTheme);

    return musicTheme;
}