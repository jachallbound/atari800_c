/* Macros and data structures for registers and other values */
/* Macros */
/* Color registers */
#define CHARACTERLUMINANCE (*((int *) 709))
#define BACKGROUNDCOLOR (*((int *) 710))
#define BORDERCOLOR (*((int *) 711))
#define CURSORINHIBIT (*((int *) 752))

/* Functions */
#define POKE(reg, value) reg = value
#define SETCOLOR(reg, hue, lum) POKE(reg, hue*16 + lum)


/* Color enum */
typedef enum color_codes {
  BLACK = 0,
  BROWN = 1,
  REDORANGE = 2,
  DARKORANGE = 3,
  RED = 4,
  DEEPLAVENDER = 5,
  DEEPBLUEGREEN = 6,
  ULTRAMARINEBLUE = 7,
  MEDIUMBLUE = 8,
  DEEPBLUE = 9,
  BLUEGRAY = 10,
  OLIVE = 11,
  MEDIUMGREEN = 12,
  DEEPGREEN = 13,
  ORANGEGREEN = 14,
  ORANGE = 15
} color_codes;