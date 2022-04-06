void is_selected(int cursor[2], int x, int y)
{
    if (x == cursor[0] && y == cursor[1])
    {
        change_color(112);
    }
    else
    {
        change_color(143);
    }
}
int has_plays(int board[3][3])
{
    int has_space = 0;
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (board[x][y] == EMPTY)
            {
                has_space = 1;
            }
        }
    }
    return has_space;
}

int has_winner(int board[3][3])
{
    // verificando horizontal
    for (int y = 0; y < 3; y++)
    {

        if (board[0][y] + board[1][y] + board[2][y] == X * 3)
        {
            return X;
        }
        else if (board[0][y] + board[1][y] + board[2][y] == O * 3)
        {
            return O;
        }
    }
    // verificando Vertical
    for (int x = 0; x < 3; x++)
    {
        if (board[x][0] + board[x][1] + board[x][2] == X * 3)
        {
            return X;
        }
        else if (board[x][0] + board[x][1] + board[x][2] == O * 3)
        {
            return O;
        }
    }
    // Verificando Diagonal
    int sum = board[0][2] + board[1][1] + board[2][0];
    if (sum == X * 3)
    {
        return X;
    }
    else if (sum == O * 3)
    {
        return O;
    }
    sum = board[2][2] + board[1][1] + board[0][0];
    if (sum == X * 3)
    {
        return X;
    }
    else if (sum == O * 3)
    {
        return O;
    }
    // Verificando empate
    if (!has_plays(board))
    {
        return TIE;
    }

    return EMPTY;
}

void print_board(int board[3][3], int cursor[2])
{
    for (int y = 0; y < 3; y++)
    {
        printf("                     ");
        for (int x = 0; x < 3; x++)
        {
            if (board[x][y] == X)
            {
                is_selected(cursor, x, y);
                printf("X");
                change_color(143);
            }
            else if (board[x][y] == O)
            {
                is_selected(cursor, x, y);
                printf("O");
                change_color(143);
            }
            else
            {
                is_selected(cursor, x, y);
                printf(" ");
                change_color(143);
            }
            if (x != 2)
            {
                printf(" | ");
            }
        }
        printf("                    ");
        printf("\n");
        if (y != 2)
        {
            printf("                     --+---+--                    \n");
        }
    }
}
int change_turn(int turn)
{
    return turn == X ? O : X;
}

int get_score(int board[3][3], int turn)
{
    if (has_winner(board) == turn)
    {
        return 10;
    }
    if (has_winner(board) == change_turn(turn))
    {
        return -10;
    }
    return 0;
}

int *get_computer_move(int board[3][3], int turn, int *depth)
{
    int move_list[8][2];
    int move_count = 0;

    // Pegando espaços vazios do tabuleiro

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (board[x][y] == EMPTY)
            {
                move_list[move_count][0] = x;
                move_list[move_count][1] = y;
                move_count++;
            }
        }
    }

    // Loop passando em todos os espaços vazios
    for (int i = 0; i < 8; i++)
    {
    }
}
