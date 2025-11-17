#include "raylib.h"
#include "load.h"
#include <stdio.h>

Music music_menu(){ 
    Music musicTheme = LoadMusicStream("assets/hwh_music.mp3");
    if (IsMusicValid(musicTheme)) PlayMusicStream(musicTheme);

    return musicTheme;
}