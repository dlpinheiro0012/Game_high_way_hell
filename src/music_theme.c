#include <stdio.h>
#include "raylib.h"
#include "load_music.h"

void init_music() {
    Music musicTheme = LoadMusicStream("assets\music_HWH.mp3");
    if (IsMusicValid(musicTheme)) PlayMusicStream(musicTheme);
}