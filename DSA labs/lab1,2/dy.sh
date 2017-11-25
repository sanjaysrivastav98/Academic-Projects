gcc dylist.h
gcc -c dylist.c
gcc -c driverdy.c
gcc -o exe dylist.o driverdy.o
./exe sidy.txt
