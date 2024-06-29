#ifndef AWAKENUNTODARKNESS_H
#define AWAKENUNTODARKNESS_H

#include <stdio.h>
#include <string.h>

#include "atari800.h"

/* 
Macros
 */
#define DEBUG 1
#define STRL 128

/*
Data structures
 */

/* Game state */
typedef enum state {
  STOP = 0,
  RUN = 1,
  INTRO = 2,
  PLAYSOUND = 3,
} state;

/* 
Function Declarations
 */
void game_tick(state* game_state);
void handle_sound(char* in, char* out);

/*
Function Definitions
 */
/* Main game loop */
void game_tick(state* game_state) {
  /* Variables */
  int i = 0, ii = 0, iii = 0;
  char in[STRL], out[STRL];

  /* Prompt */
  switch (*game_state) {
  case (INTRO):
    strncpy(out, "What is your name?: ", STRL-1);
    *game_state = RUN;
    break;
  case (RUN):
    strncpy(out, "Anything else?: ", STRL-1);
    break;
  case (PLAYSOUND):
    handle_sound(in, out);
    break;
  case (STOP):
    strncpy(out, "Goodbye\n", STRL-1);
    break;
  }
  printf("%s", out);
  
  /* Answer */
  scanf("%s", in);

  /* Response */
  printf("Hello, %s!\n", in);
  if (strncmp(in, "q", STRL-1) == 0)
    *game_state = STOP;
  else if (strncmp(in, "play", STRL-1) == 0) {
    printf("playing a sound\n");
    *game_state = PLAYSOUND;
  }

  return;
}

/* Handle playing a sound */
void handle_sound(char* in, char* out) {
  int f = 0, v = 0;
  printf("in handle_sound\n");
  do {
    /* Get frequency and volume */
    printf("Frequency: ");
    scanf("%d", &f);
    printf("Volume: ");
    scanf("%d", &v);
    v += 0xA0; /* 0xA0 is zero volume */
    printf("F: %d, V: %d\n", f, v);
    /* Set sound */
    POKE(AUDIOFREQUENCY, f);
    POKE(AUDIOCONTROL, v);
    /* Query user */
    printf("'c' to continue, 'q' to quit: ");
    scanf("%s", in);
    // strtok()
  } while (strncmp(in, "q", STRL-1) != 0);
  /* Turn off sound */
  POKE(AUDIOFREQUENCY, 0);
  POKE(AUDIOCONTROL, 0);
  return;
}

#endif /* AWAKENUNTODARKNESS_H */