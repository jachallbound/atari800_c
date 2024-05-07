# atari800_c
Simple C projects for the Atari 800.

## Requirements
Suggested requirements for compilation targeting the Atari's 6502 processor and emulation in linux follow.

### Compilation
Build using `cc65` tool. Install on Arch Linux through Arch User Repository: https://aur.archlinux.org/packages/cc65.

User linker `cl65` to build an executable: `cl65 -t atari main.c`.

### Emulation
Your new executable can be emulated using `atari800` tool. Install on Arch Linux through AUR: https://aur.archlinux.org/packages/atari800.

Emulate your program on an Atari800: `atari800 main`. Press F9 in emulator window to quit.

### Run
`run.sh` is a helper script to perform these steps.

## Font creation
Open `font/font_gimp_project.xcf` in GIMP. Draw new 8-pixel by 8-pixel character based on current layer (i.e. A, B, etc.) in black and white. Export layer as PBM with ASCII encoding. Save file same as layer name (i.e. `font/033_A.pbm`).

The BASH script `font/create_pbm_to_C.sh` will read the plain-text PBM files and create a C header file to load the binary data into RAM after launching the Atari emulator.

## Resources
Recommended programming guide: https://archive.org/details/Programmers_s_Reference_Guide_for_the_Atari_400_800_Computers.