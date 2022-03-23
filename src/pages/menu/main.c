#include "./core.c"

void start_menu()
{
    int selected_option = NEW_GAME_OPTION;

    while (1)
    {
        print_menu(selected_option);

        switch (getch())
        {
        case ARROW_DOWN:
        case KEY_S:
            if (selected_option < QUIT_OPTION)
                selected_option++;
            break;

        case ARROW_UP:
        case KEY_W:
            if (selected_option > NEW_GAME_OPTION)
                selected_option--;
            break;

        case SPACE:
        case ENTER:
            select_option_menu(selected_option);
            break;

        case ESC:
            exit(0);
        }
    }
}
