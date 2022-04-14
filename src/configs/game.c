#define BOARD_WIDTH 50 // Largura de cada linha da tela do jogo

/**
 * @brief Enum com as opções das telas do jogo
 */
enum options
{
    NEW_GAME_OPTION,
    CREDITS_OPTION,
    QUIT_OPTION,

    COOP_OPTION,
    SOLO_OPTION
};

/**
 * @brief Enum com as opção do tabuleiro ou resultado do jogo
 */
enum
{
    X = -1,
    EMPTY,
    O,
    TIE
};

/**
 * @brief Enum que será usado para acessar o array de pontuação
 * 
 */
enum
{
    T_X,  // Turn X -> Jogador 1
    T_O,  // Turn O -> Jogador 2
    T_C  // Turn Computer -> Maquina
};
