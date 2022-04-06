#include "core.c"

/**
 * @brief Função que incia o jogo coop (pessoa vs pessoa)
 */
void start_game_coop()
{
    // tabuleiro do jogo, que começa vazio
    int board[3][3] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
    };
    int key_pressed;        // Qual tecla que foi pressionada
    int cursor[2] = {0, 2}; // o ponteiro (X, Y) no tabuleiro
    int turn = X;           // De quem é a vez de jogar
    /*
     * Variável que guarda se há um vencedor.
     * EMPTY = Não há vencedor
     * X     = O jogador 1 ganhou
     * O     = O jogador 2 ganhou
     * TIE   = Houve um empate
     */
    int winner = EMPTY;

    // loop principal do jogo
    while (1)
    {
        // verificando se há um vencedor
        winner = has_winner(board);

        clear();
        change_color(143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        print_centralized("Tic Tac Toe 2077", BOARD_WIDTH, 142, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        // se tiver um ganhar, vai dar um print do resultado
        if (winner != EMPTY)
        {
            switch (winner)
            {
            case X:
                print_centralized("Jogador 1 ganhou!!!", BOARD_WIDTH, 138, 143);
                break;
            case O:
                print_centralized("Jogador 2 ganhou!!!", BOARD_WIDTH, 138, 143);
                break;
            case TIE:
                print_centralized("Empate!", BOARD_WIDTH, 140, 143);
                break;
            }
        }
        else
        {
            print_centralized("", BOARD_WIDTH, 143, 143);
        }

        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_board(board, cursor);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        change_color(-1);

        // se tiver um ganhar, vai pausar a tela
        if (winner != EMPTY)
        {
            pause();
            break; // sai do loop do jogo
        }

        // lógica que verifica o que fazer quando o jogador pressionar
        // alguma tecla
        key_pressed = getch();
        if (key_pressed == ARROW_DOWN || key_pressed == KEY_S)
        {
            if (cursor[0] < 2)
                cursor[0]++;
        }
        else if (key_pressed == ARROW_UP || key_pressed == KEY_W)
        {
            if (cursor[0] > 0)
                cursor[0]--;
        }
        else if (key_pressed == ARROW_LEFT || key_pressed == KEY_A)
        {
            if (cursor[1] > 0)
                cursor[1]--;
        }
        else if (key_pressed == ARROW_RIGHT || key_pressed == KEY_D)
        {
            if (cursor[1] < 2)
                cursor[1]++;
        }
        else if (key_pressed == ESC || key_pressed == BACKSPACE)
        {
            break;
        }
        else if (key_pressed == SPACE || key_pressed == ENTER)
        {
            if (board[cursor[0]][cursor[1]] == EMPTY)
            {
                board[cursor[0]][cursor[1]] = turn;
                turn = change_turn(turn);
            }
        }
    }
}

/**
 * @brief Função que incia o jogo solo (pessoa vs PC)
 */
void start_game_solo()
{
    // tabuleiro do jogo, que começa vazio
    int board[3][3] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
    };
    int key_pressed;        // Qual tecla que foi precionada
    int cursor[2] = {1, 1}; // o ponteiro (X, Y) no tabuleiro
    int turn = X;           // De quem é a vez de jogar
    /*
     * Variável que guarda se há um vencedor.
     * EMPTY = Não há vencedor
     * X     = O jogador 1 ganhou
     * O     = O jogador 2 ganhou
     * TIE   = Houve um empate
     */
    int winner = EMPTY;

    // loop principal do jogo
    while (1)
    {
        // verificando se há um vencedor
        winner = has_winner(board);

        clear();
        change_color(143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        print_centralized("Tic Tac Toe 2077", BOARD_WIDTH, 142, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        // se tiver um ganhar, vai dar um print do resultado
        if (winner != EMPTY)
        {
            switch (winner)
            {
            case X:
                print_centralized("Voce ganhou!!!", BOARD_WIDTH, 138, 143);
                break;
            case O:
                print_centralized("Computador ganhou!!!", BOARD_WIDTH, 138, 143);
                break;
            case TIE:
                print_centralized("Empate!", BOARD_WIDTH, 140, 143);
                break;
            }
        }
        else
        {
            print_centralized("", BOARD_WIDTH, 143, 143);
        }

        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_board(board, cursor);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        change_color(-1);

        // se tiver um ganhar, vai pausar a tela
        if (winner != EMPTY)
        {
            pause();
            break; // sai do loop do jogo
        }

        // se vai verificar qual tecla foi pressionada, se for a vez do jogador
        if (turn == X)
        {
            // lógica que verifica o que fazer quando o jogador pressionar
            // alguma tecla
            key_pressed = getch();
            if (key_pressed == ARROW_DOWN || key_pressed == KEY_S)
            {
                if (cursor[0] < 2)
                    cursor[0]++;
            }
            else if (key_pressed == ARROW_UP || key_pressed == KEY_W)
            {
                if (cursor[0] > 0)
                    cursor[0]--;
            }
            else if (key_pressed == ARROW_LEFT || key_pressed == KEY_A)
            {
                if (cursor[1] > 0)
                    cursor[1]--;
            }
            else if (key_pressed == ARROW_RIGHT || key_pressed == KEY_D)
            {
                if (cursor[1] < 2)
                    cursor[1]++;
            }
            else if (key_pressed == ESC || key_pressed == BACKSPACE)
            {
                break;
            }
            else if (key_pressed == SPACE || key_pressed == ENTER)
            {
                if (board[cursor[0]][cursor[1]] == EMPTY)
                {
                    board[cursor[0]][cursor[1]] = turn;
                    turn = change_turn(turn);
                }
            }
        }
        else // se for a vez da IA, vai pegar a jogada dela
        {
            int *move = get_computer_move(board, O);
            board[*(move + 0)][*(move + 1)] = turn;
            turn = change_turn(turn);
        }
    }
}
