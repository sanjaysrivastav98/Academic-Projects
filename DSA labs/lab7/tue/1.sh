gcc dict.h
gcc -c dict.c
gcc -c driver.c
gcc -o exe dict.o driver.o
./exe < input.txt
