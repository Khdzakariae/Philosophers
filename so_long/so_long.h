#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>

#define HEIGHT  1080
#define WIDTH   720
#define EMOGE  "pictures/pacman.xpm"
#define SPACE  "pictures/space.xpm"
#define WALL   "pictures/wall.xpm"
typedef struct s_data {
    void *mlx;
    void *win;
    int player_x;
    int player_y;
} t_data;
char map[7][19] = {
    "1111111111111111111",
    "11000P0000000000001",
    "1001111111101111101",
    "1001000000000000101",
    "1001111111100111101",
    "1000000000000000001",
    "1111111111111111111"};
// typedef struct
// {
//     void *mlx;
//     void *win;
//     int player_x;
//     int player_y;
// } t_data;



#endif