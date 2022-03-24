void select_option_new_game(int option)
{
    switch (option)
    {
    case COOP_OPTION:
        print_credits();
        break;

    case SOLO_OPTION:
        start_game_solo();
        break;

    case QUIT_OPTION:
        exit(0);
    }
}
