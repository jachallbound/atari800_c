#include <stdio.h>
#include "definitions.h"

/* Function Declarations */
void load_custom_character_set(void);

int main(void) {
  /* Define all variables */
  int i = 0;

  /* Set screen colors */
  SETCOLOR(CHARACTERLUMINANCE, RED, 8);
  SETCOLOR(BACKGROUNDCOLOR, DEEPBLUE, 0);
  SETCOLOR(BORDERCOLOR, DEEPBLUEGREEN, 0);
  /* Turn off cursor */
  POKE(CURSORINHIBIT, 0);
  /* Change left and right print margins */
  POKE(LMARGN, 3);
  POKE(RMARGN, 36);

  /* Change printf characters to custom set, and define them in RAM */
  load_custom_character_set();

  /* Print new exclamation points */
  printf(" !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

  /* Endless loop, press F9 in emulator to quit */
  while (1) {};
  return 0;
}

/* 
 * Function Definitions
*/
void load_custom_character_set(void) {
  /* Define all variables */
  long i = 0, j = 0;

  /* Change character set to one defined in RAM starting at 32768 */
  LOADCUSTOMCHARACTERSET();
  
  /* Create some custom characters */
  /* Each character is 8 bytes */
  /* First character starting at 32768 (RAMSTARTADDR) is background */
  for (i = 0; i < 8; i++) { /* Set all 8 bytes to zeros for blank background */
    POKE(REGISTERINC(RAMSTARTADDR, i), 0x00);
  }
  
  /* Next character, starting at 32776 (RAMSTARTADDR + 8) 
  corresponds to exclamation point "!" create new exclamation point */
  POKE(REGISTERINC(RAMSTARTADDR, i++), 0x00);
  POKE(REGISTERINC(RAMSTARTADDR, i++), 0x7E);
  POKE(REGISTERINC(RAMSTARTADDR, i++), 0x7E);
  POKE(REGISTERINC(RAMSTARTADDR, i++), 0x3C);
  POKE(REGISTERINC(RAMSTARTADDR, i++), 0x3C);
  POKE(REGISTERINC(RAMSTARTADDR, i++), 0x18);
  POKE(REGISTERINC(RAMSTARTADDR, i++), 0x00);
  POKE(REGISTERINC(RAMSTARTADDR, i++), 0x18);
  return;
}