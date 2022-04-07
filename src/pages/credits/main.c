/**
 * @brief unção que printa a tela de créditosF
 */
void print_credits()
{
    clear();
    change_color(143);

    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);

    print_centralized("Tic Tac Toe 2077", BOARD_WIDTH, 142, 143);

    print_centralized("Creditos", BOARD_WIDTH, 143, 143);

    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);

    print_centralized("Projeto feito na faculdade Uniamérica 2022", BOARD_WIDTH,
                      143, 143);

    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);

    print_centralized("Desenvolvedor     Leonardo Lima", BOARD_WIDTH, 143, 143);
    print_centralized("Desenvolvedor    Luiz Weinhardt", BOARD_WIDTH, 143, 143);
    print_centralized("Desenvolvedor      Rafael Alves", BOARD_WIDTH, 143, 143);
    print_centralized("Desenvolvedor  Willian Calvario", BOARD_WIDTH, 143, 143);

    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);
    print_centralized("", BOARD_WIDTH, 143, 143);
    change_color(-1);

    pause();
}
