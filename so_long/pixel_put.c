#include "so_long.h"

char map[7][19] = {
    "1111111111111111111",
    "11p0000000000000001",
    "1001111111101111101",
    "1001000000000000101",
    "1001111111100111101",
    "1000000000000000001",
    "1111111111111111111"};


// while(map[i])
// {
//     while(map[i][j])
//     {
        
//     }

// }


void draw_player(t_data *data)
{
    int i = 0;
    int j = 0;
    void *img;
    int img_width = 5;
    int img_height = 5;

    while (i < 7)
    {
        j = 0;
        while (j < 19)
        {
            if (map[i][j] == 'p')
            {
                 img = mlx_xpm_file_to_image(data->mlx, EMOGE,  &img_width, &img_height);
                 if (img != NULL)
                     mlx_put_image_to_window(data->mlx, data->win, img, data->player_x, data->player_y);
            }
            else if (map[i][j] == '1')
            {
                img = mlx_xpm_file_to_image(data->mlx, WALL, &img_width, &img_height);
                if (img != NULL)
                    mlx_put_image_to_window(data->mlx, data->win, img, j * img_width, i * img_height);
                else
                    printf("Erreur lors du chargement de l'image.\n");
            }
            else if (map[i][j] == '0')
            {
                 img = mlx_xpm_file_to_image(data->mlx, SPACE,  &img_width, &img_height);
                 if (img != NULL)
                     mlx_put_image_to_window(data->mlx, data->win, img, j * img_width, i * img_height);
            }
            j++;
        }
        i++;
    }
    // img = mlx_xpm_file_to_image(data->mlx, EMOGE, &img_width, &img_height);
    // if (img != NULL)
    //     mlx_put_image_to_window(data->mlx, data->win, img, data->player_x, data->player_y);
    // else
    //     printf("Erreur lors du chargement de l'image du joueur.\n");
}
