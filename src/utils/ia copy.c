#include <stdio.h>
#include <stdlib.h>

#define N 9

enum
{
    O,
    X,
    EMPTY
};

int HUMAN = 0;
int COMP = 1;

// returns which moves gives the maximum score
int max(int *scoreList, int moveCount, int *moveList, int *bestMove)
{

    if (!moveCount)
        return 0;

    int max = -20;

    for (int i = 0; i < moveCount; i++)
    {
        if (scoreList[i] > max)
        {
            max = scoreList[i];
            *bestMove = moveList[i];
        }
    }
    return max;
}

// returns which moves gives the minimum score
int min(int *scoreList, int moveCount, int *moveList, int *bestMove)
{

    if (!moveCount)
        return 0;

    int min = +20;

    for (int i = 0; i < moveCount; i++)
    {
        if (scoreList[i] < min)
        {
            min = scoreList[i];
            *bestMove = moveList[i];
        }
    }
    return min;
}

int minMax(int board[], int side, int *depth)
{

    int moveList[N];
    int moveCount = 0;
    int bestMove;
    int scoreList[N];
    int bestScore;

    bestScore = isAWin(board, COMP);
    if (bestScore)
        return bestScore - *depth;

    // fill the moveList[]
    for (int i = 0; i < N; i++)
    {
        if (board[i] == EMPTY)
            moveList[moveCount++] = i;
    }

    // loop through all moves
    int move;
    for (int i = 0; i < moveCount; i++)
    {

        move = moveList[i];
        makeMove(board, move, side);

        (*depth)++;
        scoreList[i] = minMax(board, !side, depth);
        (*depth)--;

        makeMove(board, move, EMPTY);
    }

    if (side == COMP)
    {
        // MAX
        bestScore = max(scoreList, moveCount, moveList, &bestMove);
    }
    if (side == HUMAN)
    {
        // MIN
        bestScore = min(scoreList, moveCount, moveList, &bestMove);
    }

    if (*depth != 0)
        return bestScore;
    else
        return bestMove;
}

int getComputerMove(int *board, int side)
{

    int depth = 0;
    int bestMove = minMax(board, side, &depth);
    printf("Searched.... bestMove: %d\n", bestMove + 1);
    return bestMove;
}


void runGame()
{

    int board[N];

    if (side == HUMAN)
    {
        // Human Move
        move = getHumanMove(board);
        makeMove(board, move, side);
        printBoard(board);
    }
    else
    {
        // Computer Move
        move = getComputerMove(board, side);
        makeMove(board, move, side);
        printBoard(board);
    }
}
