gcc qs.h
gcc pivot.h
gcc -c pivot1.c
gcc -c pivot2.c
gcc part.h
gcc -c part1.c
gcc -c part2.c
gcc -c qs.c
gcc -o qsHoareM3 pivot1.o part1.o qs.o
gcc -o qsLocalM3 qs.o part2.o pivot1.o
gcc -o qsHoareRand qs.o part1.o pivot2.o
gcc -o qsLocalRand qs.o part2.o pivot2.o
./qsHoareM3 < input.txt
