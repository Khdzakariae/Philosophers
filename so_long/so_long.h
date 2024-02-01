#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT  800
#define WIDTH   290
#define EMOGE  "pictures/kkk.xpm"
#define SPACE  "pictures/space.xpm"
#define WALL   "pictures/wall.xpm"
typedef struct s_data {
    void *mlx;
    void *win;
    int player_x;
    int player_y;
} t_data;

// typedef struct
// {
//     void *mlx;
//     void *win;
//     int player_x;
//     int player_y;
// } t_data;

int handle_mouse_click(int button, int x, int y);
int down_mousse(int button, int x, int y, t_data *data);
void draw_player(t_data *data);
int key_press(int keycode, t_data *data);


#endif