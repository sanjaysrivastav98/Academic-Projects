gcc hashset.h
gcc -c hashset.c
gcc -c driver.c
gcc -o exe hashset.o driver.o
./exe < input.txt