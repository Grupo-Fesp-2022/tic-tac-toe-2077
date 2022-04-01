int *get_max_value(int matrix[8][2])
{
    int max = matrix[0][0];

    for (int y = 0; y < 2; y++)
    {

        for (int x = 0; x < 8; x++)
        {
            if (matrix[x][y] >= max)
            {
                max = matrix[x][y];
            }
        }
    }
    return max;
}

int *get_min_value(int matrix[8][2])
{
    int min = matrix[0][0];

    for (int y = 0; y < 2; y++)
    {

        for (int x = 0; x < 8; x++)
        {
            if (matrix[x][y] <= min)
            {
                min = matrix[x][y];
            }
        }
    }
    return min;
}
