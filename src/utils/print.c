/**
 * @brief Função que printa o texto centralizado
 *
 * @param string O texto que irá ser centralizado
 * @param length O tamanho da linha final
 * @param color_before Código da cor, que irá ser usada para dar print no texto
 * @param color_after Código da cor, que irá ser usada depois do texto
 */
void print_centralized(char string[], int length, int color_before, int color_after)
{
    if (strlen(string) >= length)
    {
        change_color(color_before);
        printf("%s", string);
        change_color(color_after);
    }
    else
    {
        int before, after, blank_spaces;

        blank_spaces = length - strlen(string);
        before = blank_spaces / 2;
        after = blank_spaces / 2;

        if (before + after < blank_spaces)
        {
            before++;
        }

        for (int i = 0; i < before; i++)
        {
            printf(" ");
        }

        change_color(color_before);
        printf("%s", string);
        change_color(color_after);

        for (int i = 0; i < after; i++)
        {
            printf(" ");
        }

        printf("\n");
    }
}
