#include <stdio.h>
#include <allegro.h>

BITMAP *buffer, *img_cursor, *img_X, *img_O, *img_tabuleiro; // double buffer

//----O TAB[10] É FORMADO ASSIM
//TAB[1]||TAB[2]||TAB[3]
//TAB[4]||TAB[5]||TAB[6]
//TAB[7]||TAB[8]||TAB[9]
//
int TAB[10], CONTA_HUMANO, CONTA_PC;

//FUNÇÃO QUE INICIA TOTALMENTE A ALLEGRO
INICIA_ALLEGRO()
{
      allegro_init();
      install_keyboard();
      install_timer();
      install_mouse();
//Ajusta video para 16 bits de cores
 set_color_depth(32);

//Autodetecta a placa  de video e usa resolucao de 640x480
 set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);

if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0) != 0) {
 exit(-1);
}
}

CARREGA_OBJETOS()
{
buffer = create_bitmap(640,480);
img_cursor = load_bmp("cursor/mira2.bmp", NULL);
img_X = load_bmp("img/X.bmp", NULL);
img_O = load_bmp("img/bola.bmp", NULL);
img_tabuleiro = load_bmp("img/tabuleiro.bmp", NULL);
}
