/* Macros and data structures for registers and other values */
/* Address translation to dereferenced integer pointer */
#define REGISTER(x) (((int *) x))
#define REGISTERINC(x, i) (((int *) (x+i)))

/* Addresses */
#define LMARGN REGISTER(82)
#define RMARGN REGISTER(83)
#define CHARACTERLUMINANCE REGISTER(709)
#define BACKGROUNDCOLOR REGISTER(710)
#define BORDERCOLOR REGISTER(711)
#define CURSORINHIBIT REGISTER(752)
#define CHARACTERSETCONTROL REGISTER(756)
#define CHARACTERSETSTART REGISTER(57344)

#define RAMSTARTADDR 32768

/* Functions */
#define POKE(reg, value) *reg = value
#define SETCOLOR(reg, hue, lum) POKE(reg, (hue*16 + lum))
#define LOADCUSTOMCHARACTERSET() POKE(CHARACTERSETCONTROL, 128)


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