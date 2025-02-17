/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_making.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:54:47 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/17 17:51:25 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	put_sprites(t_mlx *mlx, int x, int y, t_img *img)
{
	int				height;
	int				width;
	unsigned int	color;

	height = 0;
	while (height < 96)
	{
		width = 0;
		while (width < 96)
		{
			color = pixel_get(img, width, height);
			my_mlx_pixel_put(&mlx->bg_img, x + width, y + height, color);
			width++;
		}
		height++;
	}
}
void	fill_bottom_map(t_mlx *mlx)
{
	int				height;
	int				width;
	int				color;
	height = 0;
	while (height < 216)
	{
		width = 0;
		while (width < mlx->pos.x * 96)
		{
			my_mlx_pixel_put(&mlx->bg_img, width, (mlx->pos.y * 96) + height,  0x0195DFD);
			width++;
		}
		height++;
	}
	height = 0;
	while (height < 152)
	{
		width = 0;
		while (width < 348)
		{
			color = pixel_get(&mlx->frame, width, height);
			my_mlx_pixel_put(&mlx->bg_img, (mlx->pos.x * 96 / 2 - 174) + width, (mlx->pos.y * 96) + height,  color);
			width++;
		}
		height++;
	}
}

// void	change_number_bg(t_mlx *mlx, int moves, t_img *img, int size)
// {
// 	int	x;
// 	int	y;
// 	int	position;

// 	position =  mlx.pos.x * 96 / 2
// 	if(size == 1)
// 		position += 34
// 	if(size == 2)
// 		position -= 18
// 	if(size == 3)
// 		position -= 71
// 	while(x < 38)
// 	{
// 		while(y < 85)
// 		{
// 			color = pixel_get(img, width, height);
// 			my_mlx_pixel_put(&mlx->bg_img, x + width, y + height, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

/* void	ft_putnbr(int moves, char **filenames, int *size)
{
	int	result;

	if (moves >= 10)
		ft_putnbr(moves / 10, filenames, size);

	result = moves % 10;
	(*size)++;
	printf("%d and the file name is..... %s and its the %d number\n", result, filenames[result], (*size));
	// change_number_bg(moves, mlx.numbers.images[result], size);
}

int CHANGETHIS(int argc, char **argv)
{
    char    *filenames[10];
    int     moves;
	int		size;
    filenames[0] = "zero.xpm";
    filenames[1] = "one.xpm";
    filenames[2] = "two.xpm";
    filenames[3] = "three.xpm";
    filenames[4] = "four.xpm";
    filenames[5] = "five.xpm";
    filenames[6] = "six.xpm";
    filenames[7] = "seven.xpm";
    filenames[8] = "eight.xpm";
    filenames[9] = "nine.xpm";
    filenames[10] = NULL;
	if (argc != 2)
		return (1);
	size = 0;
    moves = atoi(argv[1]);
	ft_putnbr(moves, filenames, &size);
	printf("\nsize = %d\n", size);
}
 */

void	put_map(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->pos.y)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				put_sprites(mlx, j * 96, i * 96, &mlx->wall);
			if (map[i][j] == 'e')
				put_sprites(mlx, j * 96, i * 96, &mlx->not_exit);
			j++;
		}
		i++;
	}
	fill_bottom_map(mlx);
	mlx->moves = 0;
	mlx->i = 0;
	mlx->player.dir = 0;
}
