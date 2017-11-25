gcc -c inordertraversal.c
gcc -c driver.c
gcc -o exe inordertraversal.o driver.o
./exe < input.txt