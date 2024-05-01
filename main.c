#include <stdio.h>
#include <stdint.h>
#include "definitions.h"

/* Function Declarations */

int main(void) {
  /* Define all variables */
  int i = 0;

  /* Set screen colors */
  SETCOLOR(CHARACTERLUMINANCE, RED, 8);
  SETCOLOR(BACKGROUNDCOLOR, DEEPLAVENDER, 0);
  SETCOLOR(BORDERCOLOR, DEEPBLUEGREEN, 0);
  /* Turn off cursor */
  POKE(CURSORINHIBIT, 1);
  /* Change left and right print margins */
  POKE(LMARGN, 3);
  POKE(RMARGN, 36);

  /* Change character set to one defined in RAM starting at 32768 */
  LOADCUSTOMCHARACTERSET();

  /* Create some custom characters */
  /* Each character is 8 bytes */
  /* First character starting at 32768 is background of all custom characters,
     so set it to blank, all zeroes */
  POKE(REGISTER(32768), 0x00);
  POKE(REGISTER(32769), 0x00);
  POKE(REGISTER(32770), 0x00);
  POKE(REGISTER(32771), 0x00);
  POKE(REGISTER(32772), 0x00);
  POKE(REGISTER(32773), 0x00);
  POKE(REGISTER(32774), 0x00);
  POKE(REGISTER(32775), 0x00);

  /* Next character, starting at 32776 corresponds to exclamation point !
     create new exclamation point */
  POKE(REGISTER(32776), 0x00);
  POKE(REGISTER(32777), 0x7E);
  POKE(REGISTER(32778), 0x7E);
  POKE(REGISTER(32779), 0x3C);
  POKE(REGISTER(32780), 0x3C);
  POKE(REGISTER(32781), 0x18);
  POKE(REGISTER(32782), 0x00);
  POKE(REGISTER(32783), 0x18);


  /* Print new exclamation point */
  printf(" !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

  /* Endless loop, press F9 in emulator to quit */
  while (1) {};
  return 0;
}