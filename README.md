# atari800_c
Simple C projects for the Atari 800.

## Requirements
Suggested requirements for compilitation targeting the Atari's 6502 processor and emulation in linux follow.

### Compilation
Build using `cc65` tool. Install on Arch Linux through Arch User Repository: https://aur.archlinux.org/packages/cc65.

User linker `cl65` to build an executable: `cl65 -t atari main.c`.

### Emulation
Your new executable can be emulated using `atari800` tool. Install on Arch Linux through AUR: https://aur.archlinux.org/packages/atari800.

Emulate your program on an Atari800: `atari800 main`.

## Resources
Recommended programming guide: https://archive.org/details/Programmers_s_Reference_Guide_for_the_Atari_400_800_Computers.