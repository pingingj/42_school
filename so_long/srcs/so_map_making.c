/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_making.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:54:47 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/19 19:06:25 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	change_number_bg(t_game *game, t_img *img, int size)
{
	int	x;
	int	y;
	int	position;
	int	color;

	y = -1;
	color = 0;
	position = game->pos.x * 96 / 2;
	if (size == 0)
		position += 50;
	if (size == 1)
		position -= 21;
	if (size == 2)
		position -= 92;
	while (++y < 101)
	{
		x = -1;
		while (++x < 42)
		{
			color = pixel_get(img, x, y);
			pixel_put(&game->bg_img, position + x, game->pos.y * 96 + y
				+ 26, color);
		}
	}
}

void	color_frame(t_game *game)
{
	int	height;
	int	width;
	int	color;

	color = 0;
	height = 0;
	width = 0;
	while (height < 152)
	{
		width = 0;
		while (width < 288)
		{
			color = pixel_get(&game->frame, width, height);
			pixel_put(&game->bg_img, (game->pos.x * 96 / 2 - 144)
				+ width, (game->pos.y * 96) + height, color);
			width++;
		}
		height++;
	}
}

void	fill_bottom_map(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < 152)
	{
		width = 0;
		while (width < game->pos.x * 96)
		{
			pixel_put(&game->bg_img, width, (game->pos.y * 96) + height,
				0x0195DFD);
			width++;
		}
		height++;
	}
	color_frame(game);
}

void	put_sprites(t_game *game, int x, int y, t_img *img)
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
			pixel_put(&game->bg_img, x + width, y + height, color);
			width++;
		}
		height++;
	}
}

void	put_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->pos.y)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				put_sprites(game, j * 96, i * 96, &game->wall);
			if (map[i][j] == 'e')
				put_sprites(game, j * 96, i * 96, &game->not_exit);
			j++;
		}
		i++;
	}
	fill_bottom_map(game);
	game->moves = 0;
	game->i = 0;
	game->player.dir = 0;
}
