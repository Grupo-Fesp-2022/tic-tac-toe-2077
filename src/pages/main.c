#include "menu/main.c"

/**
 * @brief Função principal que inicia o jogo
 */
void star_game()
{
    // linkando o array de pontuação no ponteiro global
    SCORES = calloc(3, sizeof(int));

    // Iniciando as pontuações
    SCORES[T_X] = 0;
    SCORES[T_O] = 0;
    SCORES[T_C] = 0;

    // Iniciando o jogo
    start_menu();

    // Limpando as pontuações da memória
    free(SCORES);
    SCORES = NULL;
}
