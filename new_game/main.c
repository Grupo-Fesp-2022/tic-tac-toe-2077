void print_new_game()
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

        printf("                  Modos de jogo                   \n");

        printf("                                                  \n");
        printf("                                                  \n");
        printf("                                                  \n");

        printf("                       ");
        change_color_select(position, 1);
        printf("Coop");
        change_color(143);
        printf("                       \n");

        printf("                                                  \n");
        printf("                                                  \n");

        printf("                       ");
        change_color_select(position, 2);
        printf("Solo");
        change_color(143);
        printf("                       \n");

        printf("                                                  \n");
        printf("                                                  \n");
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
        else if (newPosition == BACKSPACE_PRESSED)
        {
            break;
        }
        else
        {
            position = newPosition;
        }
    }
}