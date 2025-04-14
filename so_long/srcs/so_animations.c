/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:51:03 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/20 18:32:00 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	coin_pos(t_game *game)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	game->coin_pos = malloc(sizeof(t_pos) * game->c_amount);
	if (game->coin_pos == NULL)
		return ;
	while (++i < game->pos.y)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'c')
			{
				game->coin_pos[index].x = j;
				game->coin_pos[index].y = i;
				index++;
			}
			j++;
		}
	}
}

void	put_frame_aux(t_game *game, int index)
{
	while (index < game->c_amount)
	{
		if (game->i == 1)
			put_sprites(game, game->coin_pos[index].x * 96,
				game->coin_pos[index].y * 96, &game->coins.coin);
		if (game->i == 100)
			put_sprites(game, game->coin_pos[index].x * 96,
				game->coin_pos[index].y * 96, &game->coins.first_coin);
		if (game->i == 200)
			put_sprites(game, game->coin_pos[index].x * 96,
				game->coin_pos[index].y * 96, &game->coins.second_coin);
		if (game->i == 300)
			put_sprites(game, game->coin_pos[index].x * 96,
				game->coin_pos[index].y * 96, &game->coins.third_coin);
		if (game->i == 400)
			put_sprites(game, game->coin_pos[index].x * 96,
				game->coin_pos[index].y * 96, &game->coins.fourth_coin);
		if (game->i == 500)
			put_sprites(game, game->coin_pos[index].x * 96,
				game->coin_pos[index].y * 96, &game->coins.last_coin);
		if (game->i == 600)
			game->i = 0;
		index++;
	}
}

void	put_frame(t_game *game)
{
	put_frame_aux(game, 0);
	if ((game->i == 1 || game->i == 100 || game->i == 200 || game->i == 300
			|| game->i == 400 || game->i == 500 || game->i == 600))
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->bg_img.img, 0, 0);
		if (game->player.dir == 1)
			mlx_put_image_to_window(game->mlx, game->win,
				game->player_mirror.img, game->player.pos.x * 96,
				game->player.pos.y * 96);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->player.p_img.img, game->player.pos.x * 96,
				game->player.pos.y * 96);
	}
}

int	animation(t_game *game)
{
	static struct timeval	last_time;
	struct timeval			current_time;
	long					elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - last_time.tv_sec) * 1000
		+ (current_time.tv_usec - last_time.tv_usec) / 1000;
	if (elapsed_time >= 1)
	{
		game->i++;
		put_frame(game);
		last_time = current_time;
	}
	return (0);
}
