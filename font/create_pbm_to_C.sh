#!/bin/bash

# Begin header file
cfile=customcharacters.h
echo '#include "definitions.h"' > $cfile
echo "#ifndef CUSTOMCHARACTERS_H" >> $cfile
echo "#define CUSTOMCHARACTERS_H" >> $cfile
echo "void customcharacters(void) {" >> $cfile
echo "  ACTIVATECUSTOMCHARACTERS();" >> $cfile
echo "  /* 512 registry POKEs to define 128 new characters */" >> $cfile

# Create function calls based on created pbm files
register=32768
for f in *.pbm
do
  s=$(tail -1 $f)
  hex_number=$(printf "%016llx" "$((2#$s))")
  echo "$f: $s -> $hex_number"
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
echo "#endif /* CUSTOMCHARACTERS_H */" >> $cfile