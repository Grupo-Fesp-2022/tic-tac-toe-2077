#include <stdlib.h>
#include <windows.h>

/**
 * @brief Função para mudar a cor do print
 *
 * @param color o código da cor
 */
void change_color(int color)
{
    int color_code = 15;
    if (color <= 255 && color >= 1)
    {
        color_code = color;
    }
    
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}

void print_colors()
{
    for (int i = 1; i <= 255; i++)
    {
        change_color(i);
        printf("Codigo: %d \n", i);
    }
    change_color(-1);
}