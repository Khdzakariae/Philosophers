#include "so_long.h"

void ft_position_player(int *x, int *y)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (map[i][j] == 'P')
            {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

