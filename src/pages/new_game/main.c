#include "../game/main.c"
#include "core.c"

/**
 * @brief Função que da print na tela de "novo jogo"
 */
void print_new_game()
{
    // variáveis que guardam qual tecla foi precionada e qual a opção selecionada
    int key_pressed, selected_option;
    selected_option = COOP_OPTION;

    // loop principal do menu
    while (1)
    {
        // dando o print na tela
        clear();
        change_color(143);

        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        print_centralized("Tic Tac Toe 2077", BOARD_WIDTH, 142, 143);

        print_centralized("Modos de jogo", BOARD_WIDTH, 143, 143);

        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        print_centralized("Coop", BOARD_WIDTH,
                          get_color_from_option(selected_option, COOP_OPTION),
                          143);

        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        print_centralized("Solo", BOARD_WIDTH,
                          get_color_from_option(selected_option, SOLO_OPTION),
                          143);

        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        change_color(-1);

        // lógica para verificar o que fazer quando o usuário apertar alguma
        // tecla
        key_pressed = getch();

        if (key_pressed == ARROW_DOWN || key_pressed == KEY_S)
        {
            if (selected_option < SOLO_OPTION)
                selected_option++;
        }
        else if (key_pressed == ARROW_UP || key_pressed == KEY_W)
        {
            if (selected_option > COOP_OPTION)
                selected_option--;
        }
        else if (key_pressed == SPACE || key_pressed == ENTER)
        {
            select_option_new_game(selected_option);
            break;
        }
        else if (key_pressed == ESC || key_pressed == BACKSPACE)
        {
            break;
        }
    }
}
