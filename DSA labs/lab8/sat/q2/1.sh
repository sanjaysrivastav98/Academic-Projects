gcc bitarray.h
gcc bitvector.h
gcc bloom.h
gcc -c bitarray.c
gcc -c bitvector.c
gcc -c bloom.c -lm
gcc -c driver.c
gcc -o exe bitarray.o bitvector.o bloom.o driver.o -lm
./exe < input.txt
