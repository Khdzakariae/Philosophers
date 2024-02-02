#ifndef SO_LONG_H
#define SO_LONG_H


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"
#include <X11/keysym.h>

#define HEIGHT  1000
#define WIDTH   290
#define EMOGE  "pictures/kkkk.xpm"
#define SPACE  "pictures/space.xpm"
#define WALL   "pictures/wall.xpm"
#define PIZZA  "pictures/pizza.xpm"
#define SORTIE "pictures/bab.xpm"
#define SORTIEM "pictures/baba.xpm"



char map[7][24] = {
    "111111111111111111111111",
    "1C00000Z0000000Z0000C001",
    "100111111111111111000001",
    "10000000000C0000C1000001",
    "1P1111111110011111111101",
    "10C000C000000C00000000E1",
    "111111111111111111111111"};

typedef struct s_data {
    void *mlx;
    void *win;
    int player_x;
    int player_y;
} t_data;

int key_hook(int keysym, t_data *data);
void ft_position_player(int *x, int *y);

void draw_player(t_data *data);
void move_player(t_data *data, int dx, int dy);


#endif