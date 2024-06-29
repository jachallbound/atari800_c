rm main main.o

# Build fonts, optional
if [ $1 -eq 1 ]
then
  cd font
  ./generateheader.sh
  cd ..
fi

# Build program and emulate
cl65 --verbose \
     -Cl \
     -t \
     atari main.c &&\
rm main.o &&\
atari800 -atari main