#!/bin/bash

### Create .pbm files from gimp project
# but only if they do not already exist
# there should be 128 total files when finished
if [[ $(ls *.pbm | wc -l) -lt 128 ]]
then
  # clear old files
  rm pbm/*.pbm

  # create new files with gimp script
  gimp -i -b '(export-layers "fonts.xcf" "./pbm/")' -b '(gimp-quit 0)'

  # Fix pbm file name so they are loaded in correct order
  cd pbm
  rename "" 0"" ?.pbm
  rename "" 0"" ??.pbm
  cd ..
fi

### Create a valid C header file that defines a new
# character set starting at register 32768 (0x8000)
# Begin header file
cfile=set_font.h
echo "#ifndef SET_FONT_H" > $cfile
echo "#define SET_FONT_H" >> $cfile
echo '#include "atari800.h"' >> $cfile
echo "void set_font(void) {" >> $cfile
echo "  ACTIVATECUSTOMCHARACTERS();" >> $cfile
echo "  /* 512 registry POKEs to define 128 new characters */" >> $cfile

# Create function calls based on created pbm files
register=32768
for f in pbm/*.pbm
do
  s=$(tail -1 $f)
  hex_number=$(printf "%016llx" "$((2#$s))")
  echo "$f: $s -> $hex_number"
  echo "  /* $f */" >> $cfile
  for i in 0 4 8 12
  do
    h=${hex_number:$i:4}
    echo "  POKE(REGISTER($register), 0x${h:2:2}${h:0:2});" >> $cfile
    ((register+=2))
  done
done

# End header file
echo "  return;" >> $cfile
echo "}" >> $cfile
echo "#endif /* SET_FONT_H */" >> $cfile