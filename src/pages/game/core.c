void is_selected(int cursor[2], int x, int y){
    //TODO  : verificar o motivo de estar invertido x y
    if (x == cursor[1] && y == cursor[0])
    {
        change_color(112);
    }else{
        change_color(143);
    }
    
} 

void print_board(int board[3][3], int cursor[2])
{
    for (int i = 0; i < 3; i++)
    {
        printf("                     ");
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == X)
            {
                is_selected(cursor, i, j);
                printf("X");
                change_color(143);
            }
            else if (board[i][j] == O)
            {
                is_selected(cursor, i, j);
                printf("O");
                change_color(143);
            }
            else
            {
                is_selected(cursor, i, j);
                printf(" ");
                change_color(143);
            }
            if (j != 2)
            {
                printf(" | ");
            }
        }
        printf("                    ");
        printf("\n");
    }
}
