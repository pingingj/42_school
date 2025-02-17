/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:47:13 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/13 20:12:52 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	player_movement(int keycode, t_mlx *mlx)
{
	if (keycode == 119 && mlx->map[mlx->player.pos.y - 1]
		[mlx->player.pos.x] != '1')
		mlx->player.pos.y -= 1;
	if (keycode == 115 && mlx->map[mlx->player.pos.y + 1]
		[mlx->player.pos.x] != '1')
		mlx->player.pos.y += 1;
	if (keycode == 97 && mlx->map[mlx->player.pos.y]
		[mlx->player.pos.x - 1] != '1')
		mlx->player.pos.x -= 1;
	if (keycode == 100 && mlx->map[mlx->player.pos.y]
		[mlx->player.pos.x + 1] != '1')
		mlx->player.pos.x += 1;
	mlx->moves++;
}

void	map_updater(t_mlx *mlx, t_player *player)
{
	if (mlx->map[player->pos.y][player->pos.x] == 'c')
	{
		mlx->c_amount--;
		mlx->map[player->pos.y][player->pos.x] = 'C';
		free(mlx->coin_pos);
		coin_pos(mlx);
		put_sprites(mlx, player->pos.x * 96, player->pos.y * 96, &mlx->empty);
	}
	if (mlx->c_amount == 0)
		put_sprites(mlx, mlx->exit.pos.x * 96, mlx->exit.pos.y * 96,
			&mlx->exit.e_img);
	if (mlx->map[player->pos.y][player->pos.x] == 'e' && mlx->c_amount == 0)
		ft_destroy(mlx);
}
