/**
 * @brief Função que gerencia o que fazer, quando o usuário seleciona uma opção
 *
 * @param option Opção clicada
 */
void select_option_new_game(int option)
{
    switch (option)
    {
    case COOP_OPTION:
        start_game_coop();
        break;

    case SOLO_OPTION:
        start_game_solo();
        break;

    case QUIT_OPTION:
        exit(0);
    }
}
