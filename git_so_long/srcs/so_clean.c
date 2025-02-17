/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:41:30 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/13 19:50:51 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

int	ft_destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->wall.img);
	mlx_destroy_image(mlx->mlx, mlx->coins.coin.img);
	mlx_destroy_image(mlx->mlx, mlx->coins.first_coin.img);
	mlx_destroy_image(mlx->mlx, mlx->coins.second_coin.img);
	mlx_destroy_image(mlx->mlx, mlx->coins.third_coin.img);
	mlx_destroy_image(mlx->mlx, mlx->coins.fourth_coin.img);
	mlx_destroy_image(mlx->mlx, mlx->coins.last_coin.img);
	mlx_destroy_image(mlx->mlx, mlx->not_exit.img);
	mlx_destroy_image(mlx->mlx, mlx->exit.e_img.img);
	mlx_destroy_image(mlx->mlx, mlx->empty.img);
	mlx_destroy_image(mlx->mlx, mlx->player_mirror.img);
	mlx_destroy_image(mlx->mlx, mlx->player.p_img.img);
	mlx_destroy_image(mlx->mlx, mlx->bg_img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	print_map(*mlx);
	free(mlx->coin_pos);
	free(mlx->mlx);
	free_map(mlx);
	exit(0);
}

void	free_map(t_mlx *map)
{
	int	i;

	i = 0;
	while (i < map->pos.y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}
