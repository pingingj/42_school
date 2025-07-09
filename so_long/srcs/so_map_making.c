/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_making.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:54:47 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/09 17:07:16 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	change_number_bg(t_game *game, t_img *img, int size)
{
	int	x;
	int	y;
	int	offset;
	int	color;

	y = -1;
	color = 0;
	offset = game->pos.x * SPRITE_SZ / 2;
	if (size == 0)
		offset += 50;
	else if (size == 1)
		offset -= 21;
	else if (size == 2)
		offset -= 92;
	while (++y < NUM_H)
	{
		x = -1;
		while (++x < NUM_W)
		{
			color = pixel_get(img, x, y);
			pixel_put(&game->bg_img, offset + x, game->pos.y * SPRITE_SZ + y
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
	while (height < COUNTER_H)
	{
		width = 0;
		while (width < COUNTER_W)
		{
			color = pixel_get(&game->frame, width, height);
			pixel_put(&game->bg_img, (game->pos.x * (SPRITE_SZ / 2) - (COUNTER_W / 2))
				+ width, (game->pos.y * SPRITE_SZ) + height, color);
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
	while (height < COUNTER_H)
	{
		width = 0;
		while (width < game->pos.x * SPRITE_SZ)
		{
			pixel_put(&game->bg_img, width, (game->pos.y * SPRITE_SZ) + height,
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
	while (height < SPRITE_SZ)
	{
		width = 0;
		while (width < SPRITE_SZ)
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
				put_sprites(game, j * SPRITE_SZ, i * SPRITE_SZ, &game->wall);
			if (map[i][j] == 'e')
				put_sprites(game, j * SPRITE_SZ, i * SPRITE_SZ, &game->not_exit);
			j++;
		}
		i++;
	}
	fill_bottom_map(game);
	game->moves = 0;
	game->i = 0;
	game->player.dir = 0;
}
