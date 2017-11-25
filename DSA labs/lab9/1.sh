gcc bst.h
gcc -c bst.c
gcc -c driver.c
gcc -o exe bst.o driver.o
./exe < input.txt
