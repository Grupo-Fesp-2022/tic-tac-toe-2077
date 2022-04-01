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
    int best_move[2];
    int score_list[8][2];
    int best_score[2];
    int score;

    score = get_score(board, O);
    if (score)
        return score - *depth;

    // preenchendo move_list
    for (int y = 0; y < 3; y++)

    {
        for (int x = 0; x < 3; x++)
        {
            if (board[x][y] == EMPTY)
            {
                move_count++;
                move_list[move_count][0] = x;
                move_list[move_count][1] = y;
            }
        }
    }
    int move[2];
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            move = move_list[x][y];
            board[move[0]][move[1]] = turn;

            (*depth)++;
            score_list[x][y] = get_computer_move(board, change_turn(turn), depth);
            (*depth)--;

            board[move[0]][move[1]] = EMPTY;
        }
    }
    int max[2] = get_max_value(score_list);
    int min[2] = get_min_value(score_list);

    if (turn == O)
    {
        best_score[0] = max[0];
        best_score[1] = max[1];
    }
    if (turn == X)
    {
        best_score[0] = min[0];
        best_score[1] = min[1];
    }

    if (*depth != 0)
        return best_score;
    else
        return best_move;
}
