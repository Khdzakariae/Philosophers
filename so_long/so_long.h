#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
    void *mlx;
    void *win;
    int player_x;
    int player_y;
} t_data;


void draw_player(t_data *data);
int key_press(int keycode, t_data *data);


#endif