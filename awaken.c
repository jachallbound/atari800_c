#include <stdio.h>
#include "registers.h"



/* Function Declarations */
void setcolor(int *reg, color_codes hue, int lum);


int main(void) {
  /* Set screen colors */
  SETCOLOR(CHARACTERLUMINANCE, RED, 14);
  SETCOLOR(BACKGROUNDCOLOR, DEEPLAVENDER, 0);
  SETCOLOR(BORDERCOLOR, DEEPBLUEGREEN, 0);

  /* turn on/off cursor */
  POKE(CURSORINHIBIT, 0);

  printf("Hello, world!\n");
  

  while (1) {};
  return 0;
}

/* Function Definitions */
void setcolor(int *reg, color_codes hue, int lum) {
  *reg = hue*16 + lum;
  return;
}