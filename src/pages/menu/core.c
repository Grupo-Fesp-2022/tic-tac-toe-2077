#include "../credits/main.c"
#include "../new_game/main.c"

void print_score()
{
    char line1[12], line2[12];
    int before, after, blank_spaces;

    blank_spaces = BOARD_WIDTH - 12;
    before = blank_spaces / 2;
    after = blank_spaces / 2;

    /**
     * @brief Função privada que será usada para dar print nos espaços em branco
     *
     * @param quantity A quantidade de espaços
     */
    void print_spaces(int quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            printf(" ");
        }
    }

    if (before + after < blank_spaces)
    {
        before++;
    }

    // Dando print nos títulos

    change_color(143);
    print_spaces(before);

    change_color(138);
    printf("J1");
    change_color(143);

    printf(" | ");

    change_color(142);
    printf("J2");
    change_color(143);

    printf(" | ");

    change_color(140);
    printf("PC");
    change_color(143);

    change_color(143);
    print_spaces(before);

    printf("\n");

    // Dando print nas pontuações em si

    change_color(143);
    print_spaces(before);

    change_color(138);
    printf(SCORES[T_X] <= 9 ? "0%d" : "%d", SCORES[T_X]);
    change_color(143);

    printf(" | ");

    change_color(142);
    printf(SCORES[T_O] <= 9 ? "0%d" : "%d", SCORES[T_O]);
    change_color(143);

    printf(" | ");

    change_color(140);
    printf(SCORES[T_C] <= 9 ? "0%d" : "%d", SCORES[T_C]);
    change_color(143);

    change_color(143);
    print_spaces(before);

    printf("\n");
}

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

    print_score();

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
