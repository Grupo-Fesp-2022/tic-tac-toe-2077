#include "core.c"
void start_game_solo()
{
    int board[3][3] = {
        {X, O, X},
        {O, X, O},
        {O, X, O},
    };
    int key_pressed;
    int cursor[2] = {2, 2};

    while (1)
    {
        clear();
        change_color(143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);

        print_centralized("Tic Tac Toe 2077", BOARD_WIDTH, 142, 143);

        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_board(board, cursor);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        print_centralized("", BOARD_WIDTH, 143, 143);
        change_color(-1);
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
        //TODO : arrumar o eixo x
        else if (key_pressed == ARROW_LEFT || key_pressed == KEY_A)
        {
            if (cursor[0] < 2)
                cursor[0]++;
        }
        else if (key_pressed == ARROW_RIGHT || key_pressed == KEY_D)
        {
            if (cursor[0] > 0)
                cursor[0]--;
        }
        // else if (key_pressed == SPACE || key_pressed == ENTER)
        // {
        //     select_option_new_game(selected_option);
        // }
        // else if (key_pressed == ESC || key_pressed == BACKSPACE)
        // {
        //     break;
        // }
    }
}
