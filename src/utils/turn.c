gchar *get_turn()
{
    return (gchar *)(TURN == -1 ? "X" : "O");
}

void change_turn()
{
    TURN = TURN == -1 ? 1 : -1;
}
