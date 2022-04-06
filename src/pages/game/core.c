/**
 * @brief Função que troca a cor do print, caso a posição (X, Y) esteja selecionada.
 *
 * @param cursor Cursor do tabuleiro
 * @param x Posição X
 * @param y Posição Y
 */
void is_selected(int cursor[2], int x, int y)
{
    if (x == cursor[0] && y == cursor[1])
        change_color(112);
    else
        change_color(143);
}

/**
 * @brief Função que verifica se ainda há espaços livres para jogar.
 *
 * @param board Tabuleiro do jogo
 * @return int Retorna 1 se ainda tiver espaços, 0 se não.
 */
int has_plays(int board[3][3])
{
    int has_space = 0;
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (board[x][y] == EMPTY)
                has_space = 1;
        }
    }
    return has_space;
}

/**
 * @brief Função que retorna o ganhador do jogo.
 *
 * @param board Tabuleiro
 * @return int O jogador que ganhou, ou se deu empate, ou se não houve vencedor.
 */
int has_winner(int board[3][3])
{
    // verificando ganhador na horizontal
    for (int y = 0; y < 3; y++)
    {
        if (board[0][y] + board[1][y] + board[2][y] == X * 3)
            return X;
        else if (board[0][y] + board[1][y] + board[2][y] == O * 3)
            return O;
    }

    // verificando ganhador na vertical
    for (int x = 0; x < 3; x++)
    {
        if (board[x][0] + board[x][1] + board[x][2] == X * 3)
            return X;
        else if (board[x][0] + board[x][1] + board[x][2] == O * 3)
            return O;
    }

    // verificando ganhador na diagonal
    int sum = board[0][2] + board[1][1] + board[2][0];
    if (sum == X * 3)
        return X;
    else if (sum == O * 3)
        return O;
    sum = board[2][2] + board[1][1] + board[0][0];
    if (sum == X * 3)
        return X;
    else if (sum == O * 3)
        return O;

    // verificando se deu empate
    if (!has_plays(board))
        return TIE;

    // se não passou por nenhum return, é porque ainda não houve vencedor
    return EMPTY;
}

/**
 * @brief Função que da print no tabuleiro 3x3 do jogo
 *
 * @param board Tabuleiro
 * @param cursor Cursor atual
 */
void print_board(int board[3][3], int cursor[2])
{
    for (int x = 0; x < 3; x++)
    {
        printf("                     ");
        for (int y = 0; y < 3; y++)
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
            if (y != 2)
            {
                printf(" | ");
            }
        }
        printf("                    ");
        printf("\n");
        if (x != 2)
        {
            printf("                     --+---+--                    \n");
        }
    }
    // puts("\n\n");
}

/**
 * @brief Função que inverte o jogador.
 *
 * @param turn O jogador atual
 * @return int O próximo jogador
 */
int change_turn(int turn)
{
    return turn == X ? O : X;
}

// IA: https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/

/**
 * @brief Função que retorna a pontuação (usado para IA)
 *
 * @param board Tabuleiro atual
 * @param turn De quem é a vez
 * @return int Pontuação
 */
int get_score(int board[3][3], int turn)
{
    int winner = has_winner(board);
    if (winner == turn)
        return 10;
    if (winner == change_turn(turn))
        return -10;
    return 0;
}

/**
 * @brief Função que calcula a pontuação para o tabuleiro atual
 *
 * @param board Tabuleiro do jogo
 * @param turn Jogador atual
 * @param depth Profundidade da busca
 * @return int Pontuação com a penalidade
 */
int calculate_score(int board[3][3], int turn, int depth)
{
    int score = get_score(board, turn);
    if (score != 0)
        return score - depth;
    return score;
}

/**
 * @brief Função que executa o algoritmo mini_max
 *
 * @param board Tabuleiro do jogo
 * @param turn Jogador atual
 * @param depth Profundidade da busca
 * @return int Pontuação
 */
int mini_max(int board[3][3], int turn, int depth)
{
    int score = calculate_score(board, turn, depth);
    if (score != 0)
        return score;

    if (!has_plays(board))
        return 0;

    int best = turn == X ? 1000 : -1000;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[x][y] == EMPTY)
            {
                board[x][y] = turn;

                if (turn == O)
                    best = max(best, mini_max(board, change_turn(turn), depth + 1));
                else
                    best = min(best, mini_max(board, change_turn(turn), depth + 1));

                board[x][y] = EMPTY;
            }
        }
    }
    return best;
}

/**
 * @brief Função que retorna a jogada do PC.
 *
 * @param board Tabuleiro do jogo
 * @param turn Jogador atual
 * @return int* Vetor de duas posições com a posição escolhida
 */
int *get_computer_move(int board[3][3], int turn)
{
    int best_score = -1000;
    static int best_move[2] = {-1, -1};
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[x][y] == EMPTY)
            {
                board[x][y] = turn;

                int score = mini_max(board, turn, 1);

                board[x][y] = EMPTY;

                if (score > best_score)
                {
                    best_move[0] = x;
                    best_move[1] = y;
                    best_score = score;
                }
            }
        }
    }
    return best_move;
}
