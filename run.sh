rm main main.o

# Build fonts
cd font
./create_pbm_to_C.sh
cd ..

cl65 -t atari main.c &&\
rm main.o &&\
atari800 -atari main