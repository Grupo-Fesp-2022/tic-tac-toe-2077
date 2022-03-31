#include "core.c"
void start_game_coop()
{
    int board[3][3] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
    };
    int key_pressed;
    int cursor[2] = {0, 2};
    int turn = X;
    int winner = EMPTY;

    while (1)
    {
        winner = has_winner(board);
        clear();
        change_color(143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        print_centralized("Tic Tac Toe 2077", BOARD_WIDTH, 142, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
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
        if (winner != EMPTY)
        {
            pause();
            break;
        }
        key_pressed = getch();
        if (key_pressed == ARROW_DOWN || key_pressed == KEY_S)
        {
            if (cursor[1] < 2)
                cursor[1]++;
        }
        else if (key_pressed == ARROW_UP || key_pressed == KEY_W)
        {
            if (cursor[1] > 0)
                cursor[1]--;
        }
        else if (key_pressed == ARROW_LEFT || key_pressed == KEY_A)
        {
            if (cursor[0] > 0)
                cursor[0]--;
        }
        else if (key_pressed == ARROW_RIGHT || key_pressed == KEY_D)
        {
            if (cursor[0] < 2)
                cursor[0]++;
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
                turn = turn == X ? O : X;
            }
        }
    }
}
