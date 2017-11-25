gcc smallset.h
gcc -c smallset.c
gcc -c driver.c
gcc -o exe smallset.o driver.o
./exe < inp1.txt