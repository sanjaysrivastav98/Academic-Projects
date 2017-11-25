gcc quick.h
gcc -c quick.c
gcc -c driver.c
gcc -o exe quick.o driver.o
./exe < input.txt