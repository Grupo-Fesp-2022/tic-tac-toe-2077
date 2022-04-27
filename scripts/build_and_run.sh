#!/bin/bash

gcc -Wl,--export-all-symbols ../src/main.c -o ../build/main.exe `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
../build/main.exe
