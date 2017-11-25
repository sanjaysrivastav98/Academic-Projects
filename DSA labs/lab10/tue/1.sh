gcc lca.h
gcc -g -c lca.c
gcc -g -c driver.c
gcc -o exe lca.o driver.o
./exe < input1.txt