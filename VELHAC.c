#include <allegro.h>
#include <stdio.h>

#include "VELHAc.h"

#define COLUNA_1     100
#define COLUNA_2     220
#define COLUNA_3     340
#define LINHA_1      50
#define LINHA_2      180
#define LINHA_3      295



void REINICIA();
void BUFFER();
void DESENHA_JOGADA();
void EMPATE();
void FIM();
void FINALIZA();
void JOGADA_COMPUTADOR();
void JOGADA_MOUSE();
void MOSTRA_MATRIX();
void PERDA();
void VITORIA();



int main() {
  //Configurações iniciais
  INICIA_ALLEGRO();
  //Carrega figuras e sons
  CARREGA_OBJETOS();



	// Fica em loop até pressionar a tecla ESC
	while(!key[KEY_ESC])	{
    JOGADA_MOUSE();
    JOGADA_COMPUTADOR();
    MOSTRA_MATRIX();
    BUFFER();
    VITORIA();
    PERDA();
    EMPATE();
    }

	FIM();
}
// Esta macro converte o main para WinMain()
END_OF_MAIN();

//Funçao que finaliza o jogo
void FINALIZA() {
  rest(1000);
  REINICIA();
}

void REINICIA() {
 int ii;

  for (ii = 0; ii < 10; ii++)
    TAB[ii] =  NADA;

  if (fator_empate == 1)
    fator_empate = 0;
  else
    fator_empate = 1;

  if(VENCEU==1)
    resultado[0]++;
  else if(PERDEU==1)
    resultado[1]++;
  else if(EMPATOU==1)
    resultado[2]++;

  EMPATOU = 0;
  PERDEU = 0;
  VENCEU = 0;
  CONTA_HUMANO = 1 + fator_empate;
  CONTA_PC = 1;

}
void FIM() {
  destroy_bitmap(buffer);
  destroy_bitmap(img_cursor);
  destroy_bitmap(img_O);
  destroy_bitmap(img_tabuleiro);
  destroy_bitmap(img_X);

  // Sai do programa
	allegro_exit();
	exit(-1);
}


void BUFFER() {
  //Desenha o tabuleiro
  masked_blit(img_tabuleiro , buffer, 0, 0, 100, 50, 340, 350);
  // Desenha os X e às O
  DESENHA_JOGADA();
  //Desenha o cursor do mouse
  masked_blit(img_cursor , buffer, 0, 0, mouse_x, mouse_y, 32, 32);

  //Double Buffer
  blit(buffer,screen,0,0,0,0, 640, 480);
  clear(buffer);
  rectfill(buffer, 0, 0, 640, 480, makecol(192, 192, 192));
  rectfill(buffer, 0, 0, 100, 480, makecol(0, 0, 192));
}
void MOSTRA_MATRIX() {

  text_mode(-1);

  textprintf(buffer, font, 0, 22, -1, "| %d %d %d |",TAB[1],TAB[2],TAB[3]);
  textprintf(buffer, font, 0, 32, -1, "| %d %d %d |",TAB[4],TAB[5],TAB[6]);
  textprintf(buffer, font, 0, 42, -1, "| %d %d %d |",TAB[7],TAB[8],TAB[9]);
  textprintf(buffer, font, 0, 62, -1, "|HUMANO:%d |",CONTA_HUMANO);
  textprintf(buffer, font, 0, 72, -1, "|PC    :%d |",CONTA_PC);
  textprintf(buffer, font, 0, 102, -1, "VITORIAS: %d",resultado[0]);
  textprintf(buffer, font, 0, 112, -1, "DERROTAS: %d",resultado[1]);
  textprintf(buffer, font, 0, 122, -1, "EMPATES : %d",resultado[2]);

}

void DESENHA_JOGADA() {
  //linha 1
  if(TAB[1]==XIZ) {
      masked_blit(img_X , buffer, 0, 0, COLUNA_1, LINHA_1, 100, 100);}
  if(TAB[1]==BOLA) {
    masked_blit(img_O , buffer, 0, 0, COLUNA_1, LINHA_1, 100, 100);}

  if(TAB[4]==XIZ) {
    masked_blit(img_X , buffer, 0, 0, COLUNA_1, LINHA_2, 100, 100);}
  if(TAB[4]==BOLA) {
    masked_blit(img_O , buffer, 0, 0, COLUNA_1, LINHA_2, 100, 100);}

  if(TAB[7]==XIZ) {
    masked_blit(img_X , buffer, 0, 0, COLUNA_1, LINHA_3, 100, 100);}

  if(TAB[7]==BOLA) {
    masked_blit(img_O , buffer, 0, 0, COLUNA_1, LINHA_3, 100, 100);}

  //linha 2
  if(TAB[2]==XIZ) {
    masked_blit(img_X , buffer, 0, 0, COLUNA_2, LINHA_1, 100, 100);}

  if(TAB[2]==BOLA)  {
    masked_blit(img_O , buffer, 0, 0, COLUNA_2, LINHA_1, 100, 100);}

  if(TAB[5]==XIZ) {
    masked_blit(img_X , buffer, 0, 0, COLUNA_2, LINHA_2, 100, 100);}
  if(TAB[5]==BOLA) {
    masked_blit(img_O , buffer, 0, 0, COLUNA_2, LINHA_2, 100, 100);}

  if(TAB[8]==XIZ) {
    masked_blit(img_X , buffer, 0, 0, COLUNA_2, LINHA_3, 100, 100);}
  if(TAB[8]==BOLA) {
    masked_blit(img_O , buffer, 0, 0, COLUNA_2, LINHA_3, 100, 100);}

  //linha 3
  if(TAB[3]==XIZ) {
    masked_blit(img_X , buffer, 0, 0, COLUNA_3, LINHA_1, 100, 100);}
  if(TAB[3]==BOLA) {
    masked_blit(img_O , buffer, 0, 0, COLUNA_3, LINHA_1, 100, 100);}

  if(TAB[6]==XIZ) {
    masked_blit(img_X , buffer, 0, 0, COLUNA_3, LINHA_2, 100, 100);}
  if(TAB[6]==BOLA) {
    masked_blit(img_O , buffer, 0, 0, COLUNA_3, LINHA_2, 100, 100);}

  if(TAB[9]==XIZ) {
    masked_blit(img_X , buffer, 0, 0, COLUNA_3, LINHA_3, 100, 100);}
  if(TAB[9]==BOLA) {
    masked_blit(img_O , buffer, 0, 0, COLUNA_3, LINHA_3, 100, 100);}

}
void JOGADA_MOUSE() {
//1
  if (mouse_b & 1 & TAB[1]==0 & mouse_y >= LINHA_1-16 & mouse_y <= LINHA_1+100 & mouse_x >=COLUNA_1-16 & mouse_x <= COLUNA_1+100-16) {
    TAB[1]=XIZ;
    CONTA_HUMANO+=1;
  }
//2
  if (mouse_b & 1 & TAB[2]==0 & mouse_y >= LINHA_1-16 & mouse_y <= LINHA_1+100 & mouse_x >=COLUNA_2-16 & mouse_x <= COLUNA_2+100-16) {
    TAB[2]=XIZ;CONTA_HUMANO+=1;}
//3
  if (mouse_b & 1 & TAB[3]==0 & mouse_y >= LINHA_1-16 & mouse_y <= LINHA_1+100 & mouse_x >=COLUNA_3-16 & mouse_x <= COLUNA_3+100-16)
    {TAB[3]=XIZ;CONTA_HUMANO+=1;}
//4
  if (mouse_b & 1 & TAB[4]==0 & mouse_y >= LINHA_2-16 & mouse_y <= LINHA_2+100-16 & mouse_x >=COLUNA_1-16 & mouse_x <= COLUNA_1+100-16)
    {TAB[4]=XIZ;CONTA_HUMANO+=1;}
//5
  if (mouse_b & 1 & TAB[5]==0 & mouse_y >= LINHA_2-16 & mouse_y <= LINHA_2+100-16 & mouse_x >=COLUNA_2-16 & mouse_x <= COLUNA_2+100-16)
    {TAB[5]=XIZ;CONTA_HUMANO+=1;}
//6
  if (mouse_b & 1 & TAB[6]==0 & mouse_y >= LINHA_2-16 & mouse_y <= LINHA_2+100-16 & mouse_x >=COLUNA_3-16 & mouse_x <= COLUNA_3+100-16)
    {TAB[6]=XIZ;CONTA_HUMANO+=1;}
//7
  if (mouse_b & 1 & TAB[7]==0 & mouse_y >= LINHA_3-16 & mouse_y <= LINHA_3+100-16 & mouse_x >=COLUNA_1-16 & mouse_x <= COLUNA_1+100-16)
    {TAB[7]=XIZ;CONTA_HUMANO+=1;}
//8
  if (mouse_b & 1 & TAB[8]==0 & mouse_y >= LINHA_3-16 & mouse_y <= LINHA_3+100-16 & mouse_x >=COLUNA_2-16 & mouse_x <= COLUNA_2+100-16)
    {TAB[8]=XIZ;CONTA_HUMANO+=1;}
//9
  if (mouse_b & 1 & TAB[9]==0 & mouse_y >= LINHA_3-16 & mouse_y <= LINHA_3+100-16 & mouse_x >=COLUNA_3-16 & mouse_x <= COLUNA_3+100-16)
    {TAB[9]=XIZ;CONTA_HUMANO+=1;}

}
void VITORIA() {
//VERTICAIS
  if(TAB[1]==XIZ & TAB[2]==XIZ & TAB[3]==XIZ)
    {VENCEU=1;FINALIZA();}
  if(TAB[4]==XIZ & TAB[5]==XIZ & TAB[6]==XIZ)
    {VENCEU=1;FINALIZA();}
  if(TAB[7]==XIZ & TAB[8]==XIZ & TAB[9]==XIZ)
    {VENCEU=1;FINALIZA();}
//HORIZONTAIS
  if(TAB[1]==XIZ & TAB[4]==XIZ & TAB[7]==XIZ)
    {VENCEU=1;FINALIZA();}
  if(TAB[2]==XIZ & TAB[5]==XIZ & TAB[8]==XIZ)
    {VENCEU=1;FINALIZA();}
  if(TAB[3]==XIZ & TAB[6]==XIZ & TAB[9]==XIZ)
    {VENCEU=1;FINALIZA();}
//DIAGONAIS
  if(TAB[1]==XIZ & TAB[5]==XIZ & TAB[9]==XIZ)
    {VENCEU=1;FINALIZA();}
  if (TAB[3]==XIZ & TAB[5]==XIZ & TAB[7]==XIZ)
    {VENCEU=1;FINALIZA();}

}
void PERDA() {
//VERTICAIS
  if(TAB[1]==BOLA & TAB[4]==BOLA & TAB[7]==BOLA)
    {PERDEU=1;FINALIZA();}
  if(TAB[2]==BOLA & TAB[5]==BOLA & TAB[8]==BOLA)
    {PERDEU=1;FINALIZA();}
  if(TAB[3]==BOLA & TAB[6]==BOLA & TAB[9]==BOLA)
    {PERDEU=1;FINALIZA();}
//HORIZONTAIS
  if(TAB[1]==BOLA & TAB[2]==BOLA & TAB[3]==BOLA)
    {PERDEU=1;FINALIZA();}
  if(TAB[4]==BOLA & TAB[5]==BOLA & TAB[6]==BOLA)
    {PERDEU=1;FINALIZA();}
  if(TAB[7]==BOLA & TAB[8]==BOLA & TAB[9]==BOLA)
    {PERDEU=1;FINALIZA();}
//DIAGONAIS
  if(TAB[1]==BOLA & TAB[5]==BOLA & TAB[9]==BOLA)
    {PERDEU=1;FINALIZA();}
  if(TAB[3]==BOLA & TAB[5]==BOLA & TAB[7]==BOLA)
    {PERDEU=1;FINALIZA();}

}

void JOGADA_COMPUTADOR() {

  if(CONTA_PC < CONTA_HUMANO && !(EMPATOU && VENCEU && PERDEU) ) {
    CONTA_PC+=1;


//=========ATAQUES DO COMPUTADOR=====================

//ATAQUES NA POSIÇÃO 3
    if(TAB[1]==BOLA & TAB[2]==BOLA & TAB[3]==0 || TAB[7]==BOLA & TAB[5]==BOLA & TAB[3]==0 || TAB[9]==BOLA & TAB[6]==BOLA & TAB[3]==0) {
      TAB[3]=BOLA; return;
  }
  //ATAQUES NA POSIÇÃO 6
    if(TAB[4]==BOLA & TAB[5]==BOLA & TAB[6]==0 || TAB[3]==BOLA & TAB[9]==BOLA & TAB[6]==0) {
      TAB[6]=BOLA; return;
    }
  //ATAQUES NA POSIÇÃO 9
    if(TAB[7]==BOLA & TAB[8]==BOLA & TAB[9]==0 || TAB[1]==BOLA & TAB[5]==BOLA & TAB[9]==0 || TAB[3]==BOLA & TAB[6]==BOLA & TAB[9]==0) {
      TAB[9]=BOLA; return;
    }
  //ATAQUES NA POSIÇÃO 2
    if(TAB[1]==BOLA & TAB[3]==BOLA & TAB[2]==0 || TAB[8]==BOLA & TAB[5]==BOLA & TAB[2]==0) {
      TAB[2]=BOLA; return;
    }
  //ATAQUES NA POSIÇÃO 2
    if(TAB[2]==BOLA & TAB[5]==BOLA & TAB[8]==0 || TAB[7]==BOLA & TAB[9]==BOLA & TAB[8]==0) {
      TAB[8]=BOLA; return;
    }
  //ATAQUES NA POSIÇÃO 5
    if(TAB[7]==BOLA & TAB[3]==BOLA & TAB[5]==0 || TAB[1]==BOLA & TAB[9]==BOLA & TAB[5]==0 || TAB[2]==BOLA & TAB[8]==BOLA & TAB[5]==0 || TAB[4]==BOLA & TAB[6]==BOLA & TAB[5]==0) {
      TAB[5]=BOLA; return;
    }
  //ATAQUES NA POSIÇÃO 1
    if(TAB[2]==BOLA & TAB[3]==BOLA & TAB[1]==0 || TAB[9]==BOLA & TAB[5]==BOLA & TAB[1]==0 || TAB[7]==BOLA & TAB[4]==BOLA & TAB[1]==0) {
      TAB[1]=BOLA; return;
    }
  //ATAQUES NA POSIÇÃO 4
    if(TAB[1]==BOLA & TAB[7]==BOLA & TAB[4]==0 || TAB[5]==BOLA & TAB[6]==BOLA & TAB[4]==0) {
      TAB[4]=BOLA; return;
    }
  //ATAQUES NA POSIÇÃO 7
    if(TAB[1]==BOLA & TAB[4]==BOLA & TAB[7]==0 || TAB[3]==BOLA & TAB[5]==BOLA & TAB[7]==0 || TAB[9]==BOLA & TAB[8]==BOLA & TAB[7]==0) {
      TAB[7]=BOLA; return;
    }


  // =======FIM DOS ATAQUES DO COMPUTADOR==========


  //========DEFESAS DO COMPUTADOR=======================

  //DEFESAS NA POSIÇÃO 3
    if(TAB[1]==XIZ & TAB[2]==XIZ & TAB[3]==0 || TAB[7]==XIZ & TAB[5]==XIZ & TAB[3]==0 || TAB[9]==BOLA & TAB[6]==BOLA & TAB[3]==0) {
      TAB[3]=BOLA; return;
    }
  //DEFESAS NA POSIÇÃO 6
    if(TAB[4]==XIZ & TAB[5]==XIZ & TAB[6]==0 || TAB[3]==XIZ & TAB[9]==XIZ & TAB[6]==0) {
      TAB[6]=BOLA; return;
    }
  //DEFESAS NA POSIÇÃO 9
    if(TAB[7]==XIZ & TAB[8]==XIZ & TAB[9]==0 || TAB[1]==XIZ & TAB[5]==XIZ & TAB[9]==0 || TAB[3]==XIZ & TAB[6]==XIZ & TAB[9]==0) {
      TAB[9]=BOLA; return;
    }
  //DEFESAS NA POSIÇÃO 2
    if(TAB[1]==XIZ & TAB[3]==XIZ & TAB[2]==0 || TAB[8]==XIZ & TAB[5]==XIZ & TAB[2]==0) {
      TAB[2]=BOLA; return;
    }
  //DEFESAS NA POSIÇÃO 5
    if(TAB[7]==XIZ & TAB[3]==XIZ & TAB[5]==0 || TAB[1]==XIZ & TAB[9]==XIZ & TAB[5]==0 || TAB[2]==XIZ & TAB[8]==XIZ & TAB[5]==0 || TAB[4]==XIZ & TAB[6]==XIZ & TAB[5]==0) {
      TAB[5]=BOLA; return;
    }
  //DEFESAS NA POSIÇÃO 8
    if(TAB[2]==XIZ & TAB[5]==XIZ & TAB[8]==0 || TAB[7]==XIZ & TAB[9]==XIZ & TAB[8]==0) {
      TAB[8]=BOLA; return;
    }

  //DEFESAS NA POSIÇÃO 1
    if(TAB[2]==XIZ & TAB[3]==XIZ & TAB[1]==0 || TAB[9]==XIZ & TAB[5]==XIZ & TAB[1]==0 || TAB[7]==XIZ & TAB[4]==XIZ & TAB[1]==0) {
      TAB[1]=BOLA; return;
    }
  //DEFESAS NA POSIÇÃO 4
    if(TAB[1]==XIZ & TAB[7]==XIZ & TAB[4]==0 || TAB[5]==XIZ & TAB[6]==XIZ & TAB[4]==0) {
      TAB[4]=BOLA; return;
    }
  //DEFESAS NA POSIÇÃO 7
    if(TAB[1]==XIZ & TAB[4]==XIZ & TAB[7]==0 || TAB[3]==XIZ & TAB[5]==XIZ & TAB[7]==0 || TAB[9]==XIZ & TAB[8]==XIZ & TAB[7]==0) {
      TAB[7]=BOLA; return;
    }


  //===========FIM DAS DEFESAS DO COMPUTADOR================



  //============JOGADAS PROGRAMADAS=========================
    if(TAB[1]==0) {
      TAB[1]=BOLA; return;
    }
    if(TAB[9]==0) {
      TAB[9]=BOLA; return;
    }
    if(TAB[7]==0) {
      TAB[7]=BOLA; return;
    }
    if(TAB[3]==0) {
      TAB[3]=BOLA; return;
    }
  //============FIM DAS JOGADAS PROGRAMADAS=====================





  //===========JOGADAS INCONDICIONAIS=====================

  //SE JOGAR NO LUGAR 1
    if(TAB[1]==XIZ) {
      if(TAB[5]==0) {
        TAB[5]=BOLA; return;
      }
      else if(TAB[5]==XIZ & TAB[4]==0 ) {
        TAB[4]=BOLA; return;
      }
      else if(TAB[5]==XIZ & TAB[4]==XIZ & TAB[2]==0   ) {
        TAB[2]=BOLA; return;
      }
    }

  //SE JOGAR NO LUGAR 4
    if(TAB[4]==XIZ) {
      if(TAB[5]==0) {
        TAB[5]=BOLA;
        return;
      }
      else if(TAB[5]!=0 & TAB[1]==0) {
        TAB[1]=BOLA;
        return;
      }
      else if(TAB[1]!=0 & TAB[5]!=0 & TAB[7]==0 ) {
        TAB[7]=BOLA; return;
      }
    }

  //SE JOGAR NO LUGAR 7
    if(TAB[7]==XIZ) {
      if(TAB[5]==0) {
        TAB[5]=BOLA; return;
      }
      else if(TAB[5]!=0 & TAB[4]==0) {
        TAB[4]=BOLA; return;
      }
      else if(TAB[4]!=0 & TAB[5]!=0 & TAB[8]==0 ) {
        TAB[8]=BOLA; return;
      }
    }

  //SE JOGAR NO LUGAR 2
    if(TAB[2]==XIZ) {
      if(TAB[5]==0) {
        TAB[5]=BOLA; return;
      }
      else if(TAB[5]!=0 & TAB[1]==0) {
        TAB[1]=BOLA; return;
      }
      else if(TAB[1]!=0 & TAB[5]!=0 & TAB[3]==0 ) {
        TAB[3]=BOLA; return;
      }
    }

  //SE JOGAR NO LUGAR 5
    if(TAB[5]==XIZ) {
      if(TAB[1]==0) {
        TAB[1]=BOLA; return;
      }
      else if(TAB[1]!=0 & TAB[2]==0) {
        TAB[2]=BOLA; return;
      }
      else if(TAB[1]!=0 & TAB[2]!=0 & TAB[3]==0)  {
        TAB[3]=BOLA; return;
      }
      if(TAB[1]!=0 & TAB[2]!=0 & TAB[3]!=0 & TAB[4]==0) {
        TAB[4]=BOLA; return;
      }
      if(TAB[1]!=0 & TAB[2]!=0 & TAB[3]!=0 & TAB[4]!=0 & TAB[6]==0  ) {
        TAB[6]=BOLA; return;
      }
      if(TAB[1]!=0 & TAB[2]!=0 & TAB[3]!=0 & TAB[4]!=0 & TAB[6]!=0 & TAB[7]==0 ) {
        TAB[7]=BOLA; return;
      }
      if(TAB[1]!=0 & TAB[2]!=0 & TAB[3]!=0 & TAB[4]!=0 & TAB[6]!=0 & TAB[7]!=0 & TAB[9]==0 ) {
        TAB[9]=BOLA; return;
      }
    }

  //SE JOGAR NO LUGAR 8
    if(TAB[8]==XIZ) {
      if(TAB[5]==0) {
        TAB[5]=BOLA; return;
      }
      else if(TAB[5]!=0 & TAB[7]==0 ) {
        TAB[7]=BOLA; return;
      }
      else if(TAB[7]!=0 & TAB[5]!=0 & TAB[9]==0   ) {
        TAB[9]=BOLA; return;
      }
    }

  //SE JOGAR NO LUGAR 3
    if(TAB[3]==XIZ) {
      if(TAB[5]==0) {
        TAB[5]=BOLA; return;
      }
      else if(TAB[5]!=0 & TAB[2]==0 ) {
        TAB[2]=BOLA; return;
      }
      else if(TAB[2]!=0 & TAB[5]!=0 & TAB[6]==0   ) {
        TAB[6]=BOLA; return;
      }
    }

  //SE JOGAR NO LUGAR 6
    if(TAB[6]==XIZ) {
      if(TAB[5]==0) {
        TAB[5]=BOLA; return;
      }
      else if(TAB[5]!=0 & TAB[3]==0 ) {
        TAB[3]=BOLA; return;
      }
      else if(TAB[3]!=0 & TAB[5]!=0 & TAB[9]==0   ) {
        TAB[9]=BOLA; return;
      }
    }


  //SE JOGAR NO LUGAR 9
    if(TAB[9]==XIZ) {
      if(TAB[5]==0) {
        TAB[5]=BOLA; return;
      }
      else if(TAB[5]!=0 & TAB[6]==0 ) {
        TAB[6]=BOLA; return;
      }
      else if(TAB[6]!=0 & TAB[5]!=0 & TAB[8]==0   ) {
        TAB[8]=BOLA; return;
      }
    }
//========FIM DAS JOGADAS INCONDICIONAIS================
  }
}

void EMPATE() {
  if(TAB[1]!=0 & TAB[2]!=0 & TAB[3]!=0 & TAB[4]!=0 & TAB[6]!=0 & TAB[7]!=0 & TAB[8]!=0 & TAB[9]!=0 ) {

    EMPATOU=1;
    FINALIZA();
  }
}

