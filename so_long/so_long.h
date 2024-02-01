#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>

#define HEIGHT  800
#define WIDTH   290
#define EMOGE  "pictures/kkkk.xpm"
#define SPACE  "pictures/space.xpm"
#define WALL   "pictures/wall.xpm"
#define PIZZA  "pictures/pizza.xpm"
#define SORTIE "pictures/bab.xpm"
#define SORTIEM "pictures/baba.xpm"
typedef struct s_data {
    void *mlx;
    void *win;
    int player_x;
    int player_y;
} t_data;
char map[7][19] = {
    "1111111111111111111",
    "1P000C00000C0000001",
    "1001C11111101111101",
    "1001000000000000101",
    "10011111C1100111101",
    "10000C00000000C00E1",
    "1111111111111111111"};
// typedef struct
// {
//     void *mlx;
//     void *win;
//     int player_x;
//     int player_y;
// } t_data;



#endif