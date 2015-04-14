#! /bin/bash

gcc -c -Wall redblacktree.c -o redblacktree.o
gcc -c -Wall main.c -o main.o
gcc *.o -o run
