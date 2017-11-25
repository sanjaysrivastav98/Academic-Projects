gcc avltree.h
gcc -c avltree.c
gcc -c driver.c
gcc -o exe avltree.o driver.o
./exe < input.txt