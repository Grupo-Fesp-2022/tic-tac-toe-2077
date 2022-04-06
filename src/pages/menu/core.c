#include "../credits/main.c"
#include "../new_game/main.c"

/**
 * @brief Função que da print no menu inicial do jogo
 *
 * @param selected_option Opção selecionada no momento
 */
void print_menu(int selected_option)
{
    clear();
    change_color(143);
    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);

    print_centralized("Tic Tac Toe 2077", BOARD_WIDTH, 142, 143);

    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);

    print_centralized("Novo Jogo", BOARD_WIDTH,
                      get_color_from_option(selected_option, NEW_GAME_OPTION),
                      143);

    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);

    print_centralized("Creditos", BOARD_WIDTH,
                      get_color_from_option(selected_option, CREDITS_OPTION),
                      143);

    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);

    print_centralized("Sair", BOARD_WIDTH,
                      get_color_from_option(selected_option, QUIT_OPTION),
                      143);

    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);
    change_color(-1);
}

/**
 * @brief Função que é chamada quando o usuário entra em alguma opção no menu
 * 
 * @param option Qual opção foi clicada
 */
void select_option_menu(int option)
{
    // lógica para verificar qual opção foi clicada
    switch (option)
    {
    case NEW_GAME_OPTION:
        print_new_game();
        break;

    case CREDITS_OPTION:
        print_credits();
        break;

    case QUIT_OPTION:
        exit(0);
    }
}
