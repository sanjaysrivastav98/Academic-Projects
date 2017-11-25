gcc set.h
gcc -c set.c
gcc -c driver.c
gcc -o exe set.o driver.o
./exe < input.txt