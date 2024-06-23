#include <stdio.h>
#include "atari800.h"
#include "font/set_font.h"

int main(void) {
  /* Define all variables */
  int i = 0;


  /* Set screen colors */
  SETCOLOR(CHARACTERLUMINANCE, RED, 8);
  SETCOLOR(BACKGROUNDCOLOR, DEEPBLUE, 0);
  SETCOLOR(BORDERCOLOR, DEEPBLUEGREEN, 0);
  /* Turn on/off cursor */
  POKE(CURSORINHIBIT, 0);
  /* Change left and right print margins */
  POKE(LMARGN, 3);
  POKE(RMARGN, 36);

  /* Change printf characters to custom set, and define them in RAM */
  set_font();

  /* Print entire custom character set */
  printf(" !\"#$%%&'()*+,-./ \n");
  printf("0123456789\n");
  printf("ABCEDFGHIJKLMNOPQRSTUVWXYZ \n");
  printf("abcdefghijklmnopqrstuvwxyz \n");
  printf("\n");
  
  /* Endless loop, press F9 in emulator to quit */
  while (1) {};
  return 0;
}