#!/bin/bash

gcc -Wl,--export-all-symbols ../src/main.c -o ../build/main.exe `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
GTK_THEME=Adwaita:dark ../build/main.exe
