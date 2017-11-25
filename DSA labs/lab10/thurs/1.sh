gcc dnstree.h
gcc -c dnstree.c
gcc -c driver.c
gcc -o exe dnstree.o driver.o
./exe < input.txt