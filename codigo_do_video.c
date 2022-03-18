// código do vídeo https://youtu.be/StEBDXY2WBk

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void menu() {
    system("cls");
    printf("\n\n\n");

    int keyPressed = 0;
    int position = 1;
    int maxOption = 4; // a quantidade de opções que tem

    while (keyPressed != 13) {
        system("cls");
        printf("\n\n\n");

        arrowHere(1, position);
        printf("Opção 1");
        arrowHere(2, position);
        printf("Opção 2");
        arrowHere(3, position);
        printf("Opção 3");
        arrowHere(4, position);
        printf("Opção 4");

        keyPressed = getch();

        if (keyPressed == 80 && position != maxOption) {
            position++;
        } else if (keyPressed == 72 && position != 1) {
            position--;
        } else {
            position = position;
        }
    }
    printf("\n\nVocê selecionou a opção %d", position);
}

void arrowHere(int realPosition, int arrowPosition) {
    if (realPosition == arrowPosition) {
        printf("->");
    } else {
        printf("  ");
    }
}

int main() {
    menu();
    return 0;
}
