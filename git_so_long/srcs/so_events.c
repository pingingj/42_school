/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:47:13 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/10 17:50:13 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	player_movement(int keycode, t_mlx *mlx)
{
	if (keycode == 119 && mlx->map[mlx->player.pos.y - 1]
		[mlx->player.pos.x] != '1')
	{
		mlx->player.pos.y -= 1;
		mlx->moves++;
	}
	if (keycode == 115 && mlx->map[mlx->player.pos.y + 1]
		[mlx->player.pos.x] != '1')
	{
		mlx->player.pos.y += 1;
		mlx->moves++;
	}
	if (keycode == 97 && mlx->map[mlx->player.pos.y]
		[mlx->player.pos.x - 1] != '1')
	{
		mlx->player.pos.x -= 1;
		mlx->moves++;
	}
	if (keycode == 100 && mlx->map[mlx->player.pos.y]
		[mlx->player.pos.x + 1] != '1')
	{
		mlx->player.pos.x += 1;
		mlx->moves++;
	}
}
