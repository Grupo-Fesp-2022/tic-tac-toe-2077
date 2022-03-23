#include <stdio.h>

#include "./variables.c"
#include "./utils.c"
#include "../credits/main.c"
#include "../new_game/main.c"

void start_menu()
{
    int position = 1;
    int maxPosition = 3;
    int newPosition;

    while (1)
    {
        clear();
        change_color(143);
        printf("                                                  \n");
        printf("                                                  \n");
        
        printf("                 ");
        change_color(142);
        printf("Tic Tac Toe 2077");
        change_color(143);
        printf("                 \n");

        printf("                                                  \n");
        printf("                                                  \n");
        printf("                                                  \n");

        printf("                     ");
        change_color_select(position, 1);
        printf("Novo Jogo");
        change_color(143);
        printf("                    \n");

        printf("                                                  \n");
        printf("                                                  \n");

        printf("                     ");
        change_color_select(position, 2);
        printf("Creditos");
        change_color(143);
        printf("                     \n");

        printf("                                                  \n");
        printf("                                                  \n");

        printf("                       ");
        change_color_select(position, 3);
        printf("Sair");
        change_color(143);
        printf("                       \n");

        printf("                                                  \n");
        printf("                                                  \n");
        printf("                                                  \n");
        change_color(-1);

        newPosition = handle_keyboard(position, maxPosition);
        if (newPosition == ENTER_PRESSED)
        {
            switch (position)
            {
            case 1:
                print_new_game();
                break;

            case 2:
                print_credits();
                break;

            case 3:
                exit(0);
                break;

            default:
                position = 1;
            }
        }
        else
        {
            position = newPosition;
        }
    }
}
