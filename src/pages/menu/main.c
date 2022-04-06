#include "./core.c"

/**
 * @brief Função que inicia o menu inicial
 */
void start_menu()
{
    // variável que guarda a opção que está selecionada no menu
    int selected_option = NEW_GAME_OPTION;

    // loop principal do menu
    while (1)
    {
        // dando print no menu, com a opção selecionada
        print_menu(selected_option);

        // lógica para cada tecla precionada
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
