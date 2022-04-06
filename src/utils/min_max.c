/**
 * @brief Obtém o maior número de uma lista de números
 *
 * @param list A lista de números
 * @return int* O maior número da lista. Nulo se a lista for vazia.
 */
int *get_max_value(CList *list)
{
    // se a lista estiver vazia, retorna Nulo
    if (list->count(list) == 0) return NULL;

    // se só tiver 1 item na lista, retorna ele
    if (list->count(list) == 1) return list->at(list, 0);

    // iniciando a variável que irá armazenar o maior valor encontrado
    void *max = list->at(list, 0);

    // passando em todas as posições da lista, verificando se há um número maior
    for (int i = 0; i < list->count(list); i++)
    {
        if (list->at(list, i) > max)
        {
            // se achar, vai substituir
            max = list->at(list, i);
        }
    }

    // retornando o maior valor encontrado
    return max;
}

/**
 * @brief Obtém o menor número de uma lista de números
 *
 * @param list A lista de números
 * @return int* O menor número da lista. Nulo se a lista for vazia.
 */
int *get_min_value(CList *list)
{
    // se a lista estiver vazia, retorna Nulo
    if (list->count(list) == 0) return NULL;

    // se só tiver 1 item na lista, retorna ele
    if (list->count(list) == 1) return list->at(list, 0);

    // iniciando a variável que irá armazenar o menor valor encontrado
    void *min = list->at(list, 0);

    // passando em todas as posições da lista, verificando se há um número menor
    for (int i = 0; i < list->count(list); i++)
    {
        if (list->at(list, i) <= min)
        {
            // se achar, vai substituir
            min = list->at(list, i);
        }
    }

    // retornando o menor valor encontrado
    return min;
}
