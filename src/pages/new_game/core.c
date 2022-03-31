void select_option_new_game(int option)
{
    switch (option)
    {
    case COOP_OPTION:
        start_game_coop();
        break;

    case SOLO_OPTION:
        print_credits();
        break;

    case QUIT_OPTION:
        exit(0);
    }
}
