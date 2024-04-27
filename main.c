#include <stdio.h>
#include "definitions.h"

/* Function Declarations */

int main(void) {
  /* Set screen colors */
  SETCOLOR(CHARACTERLUMINANCE, RED, 14);
  SETCOLOR(BACKGROUNDCOLOR, DEEPLAVENDER, 0);
  SETCOLOR(BORDERCOLOR, DEEPBLUEGREEN, 0);

  /* turn on/off cursor */
  POKE(CURSORINHIBIT, 0); /* 0 = on, 1 = off */

  printf("Hello, world!\n");
  

  while (1) {}; /* Endless loop, press F9 in emulator to quit */
  return 0;
}