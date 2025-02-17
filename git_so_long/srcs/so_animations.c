/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:51:03 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/13 20:50:57 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	coin_pos(t_mlx *mlx)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	mlx->coin_pos = malloc(sizeof(t_pos) * mlx->c_amount);
	if (mlx->coin_pos == NULL)
		return ;
	while (++i < mlx->pos.y)
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'c')
			{
				mlx->coin_pos[index].x = j;
				mlx->coin_pos[index].y = i;
				index++;
			}
			j++;
		}
	}
}

void	put_frame_aux(t_mlx *mlx, int index)
{
	while (index < mlx->c_amount)
	{
		if (mlx->i == 1)
			put_sprites(mlx, mlx->coin_pos[index].x * 96, mlx->coin_pos[index].y
				* 96, &mlx->coins.coin);
		if (mlx->i == 100)
			put_sprites(mlx, mlx->coin_pos[index].x * 96, mlx->coin_pos[index].y
				* 96, &mlx->coins.first_coin);
		if (mlx->i == 200)
			put_sprites(mlx, mlx->coin_pos[index].x * 96, mlx->coin_pos[index].y
				* 96, &mlx->coins.second_coin);
		if (mlx->i == 300)
			put_sprites(mlx, mlx->coin_pos[index].x * 96, mlx->coin_pos[index].y
				* 96, &mlx->coins.third_coin);
		if (mlx->i == 400)
			put_sprites(mlx, mlx->coin_pos[index].x * 96, mlx->coin_pos[index].y
				* 96, &mlx->coins.fourth_coin);
		if (mlx->i == 500)
			put_sprites(mlx, mlx->coin_pos[index].x * 96, mlx->coin_pos[index].y
				* 96, &mlx->coins.last_coin);
		if (mlx->i == 600)
			mlx->i = 0;
		index++;
	}
}

void	put_frame(t_mlx *mlx)
{
	put_frame_aux(mlx, 0);
	if ((mlx->i == 1 || mlx->i == 100 || mlx->i == 200 || mlx->i == 300
			|| mlx->i == 400 || mlx->i == 500 || mlx->i == 600))
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg_img.img, 0, 0);
		if (mlx->player.dir == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player_mirror.img,
				mlx->player.pos.x * 96, mlx->player.pos.y * 96);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player.p_img.img,
				mlx->player.pos.x * 96, mlx->player.pos.y * 96);
	}
}

int	animation(t_mlx *mlx)
{
	static struct timeval	last_time;
	struct timeval			current_time;
	long					elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - last_time.tv_sec) * 1000
		+ (current_time.tv_usec - last_time.tv_usec) / 1000;
	if (elapsed_time >= 1)
	{
		put_frame(mlx);
		mlx->i++;
		last_time = current_time;
	}
	return (0);
}
