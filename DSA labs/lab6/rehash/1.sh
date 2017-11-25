gcc rehash.h
gcc -c -lm rehash.c
gcc -c driver.c
gcc -o exe rehash.o driver.o
./exe <input.txt
