int *get_max_value(CList *list)
{
    void *max = list->at(list, 0);

    for (int i = 0; i < list->count(list); i++)
    {
        if (list->at(list, i) > max)
        {
            max = list->at(list, i);
        }
    }

    return max;
}

int *get_min_value(CList *list)
{
    void *min = list->at(list, 0);

    for (int i = 0; i < list->count(list); i++)
    {
        if (list->at(list, i) <= min)
        {
            min = list->at(list, i);
        }
    }

    return min;
}
