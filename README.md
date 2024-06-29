# atari800_c
Write programs for the Atari 800 in plain C, as opposed to BASIC or assembly.

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
Font creation is optional, as all fonts are already precompiled into the C header file, this is offered if you would like to change the fonts.

Open `font/fonts.xcf` in GIMP. Draw new 8-pixel by 8-pixel character based on current layer name (i.e. A, B, etc.) in black and white. Do not change layer sequence.

Each layer must be exported to separate ASCII .PBM files. This is automated with the `export-layers.scm` GIMP Script-Fu procedure, available at https://github.com/jachallbound/gimp-export-layers-scriptfu/.

The BASH script `font/generateheader.sh` will read the plain-text PBM files and create a C header file to load the binary data into RAM after launching the Atari emulator.

Run program with `run.sh 1` to activate the font creation process.

## Resources
Recommended programming guide: https://archive.org/details/Programmers_s_Reference_Guide_for_the_Atari_400_800_Computers.

### Provided Fonts
Provided fonts are based on ZX Spectrum game, War-lord (aka Wartorn) https://worldofspectrum.org/archive/software/text-adventures/war-lord-.