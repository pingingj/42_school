/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_making.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:54:47 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/10 17:55:47 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	put_sprites(t_mlx *mlx, int x, int y, t_img *img)
{
	int				height;
	int				width;
	unsigned int	color;

	height = 0;
	while (height <= 96)
	{
		width = 0;
		while (width <= 96)
		{
			color = pixel_get(img, width, height);
			my_mlx_pixel_put(&mlx->bg_img, x + width, y + height, color);
			width++;
		}
		height++;
	}
}

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
			if (map[i][j] == 'c')
				put_sprites(mlx, j * 96, i * 96, &mlx->collectible);
			j++;
		}
		i++;
	}
}
