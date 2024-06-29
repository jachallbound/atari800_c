#include <stdio.h>
#include <string.h>

#include "atari800.h"
#include "font/set_font.h"
#include "awakenuntodarkness.h"

int main(void) {
  /* Define all variables */
  state GAMESTATE = INTRO;

  /* 
  SETUP
   */
  /* Set screen colors */
  SETCOLOR(CHARACTERLUMINANCE, RED, 8);
  SETCOLOR(BACKGROUNDCOLOR, DEEPBLUE, 0);
  SETCOLOR(BORDERCOLOR, DEEPBLUEGREEN, 0);
  /* Turn on/off cursor */
  POKE(CURSORINHIBIT, 0);
  /* Change left and right print margins */
  POKE(LMARGN, 0);
  POKE(RMARGN, 40);
  /* Change printf characters to custom set, and define them in RAM */
  set_font();

  #if DEBUG
  /* Print entire custom character set, for testing */
  printf(" !\"#$%%&'()*+,-./\\[]^_:;<>?@ \n");
  printf("0123456789\n");
  printf("ABCEDFGHIJKLMNOPQRSTUVWXYZ \n");
  printf("abcdefghijklmnopqrstuvwxyz \n");
  printf("\n");
  #endif /* DEBUG */

  /*
  LOOP
   */
  while (GAMESTATE != STOP) {
    game_tick(&GAMESTATE);
  }


  return 0;
}