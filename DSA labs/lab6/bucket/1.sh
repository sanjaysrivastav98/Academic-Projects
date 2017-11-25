#!/bin/bash
gcc -c zbucket.c
gcc -c driver.c
gcc -o exe zbucket.o driver.o zbucket.h
./exe < input.txt
