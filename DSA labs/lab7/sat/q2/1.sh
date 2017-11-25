gcc radix.h
gcc -c radix1.c
gcc -c driver.c
gcc -o exe radix1.o driver.o
./exe < input.txt