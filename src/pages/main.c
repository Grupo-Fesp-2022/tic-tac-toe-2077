#include "menu/main.c"

/**
 * @brief Função principal que inicia o jogo
 */
void star_game()
{
    // linkando o array de pontuação no ponteiro global
    SCORES = calloc(3, sizeof(int));

    // Iniciando o jogo
    start_menu();

    // Limpando as pontuações da memória
    free(SCORES);
    SCORES = NULL;
}
