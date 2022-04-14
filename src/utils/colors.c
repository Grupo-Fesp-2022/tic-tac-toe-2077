/**
 * @brief Função para mudar a cor do print
 *
 * @param color O código da cor
 */
void change_color(int color)
{
    int color_code = 15;
    if (color <= 255 && color >= 1)
    {
        color_code = color;
    }

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}

/**
 * @brief Da um print em todas as cores possíveis
 */
void print_colors()
{
    for (int i = 1; i <= 255; i++)
    {
        change_color(i);
        printf("Codigo: %d \n", i);
    }
    change_color(-1);
}

/**
 * @brief Função que retorna a cor usada para selecionar uma opção
 *
 * @param selected_option O número da opção selecionada atualmente
 * @param option_number O número da opção que será usado para saber se ela está selecionada ou não
 * @return int
 */
int get_color_from_option(int selected_option, int option_number)
{
    if (selected_option == option_number)
    {
        return 112;
    }
    return 143;
}
