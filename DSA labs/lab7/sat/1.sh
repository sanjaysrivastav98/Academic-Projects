gcc radix.h
gcc -c radix.c
gcc -c driver.c
gcc -o exe radix.o driver.o
./exe < input.txt