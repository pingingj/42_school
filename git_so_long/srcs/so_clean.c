/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:41:30 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/10 18:01:47 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

int	ft_destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->wall.img);
	mlx_destroy_image(mlx->mlx, mlx->collectible.img);
	mlx_destroy_image(mlx->mlx, mlx->not_exit.img);
	mlx_destroy_image(mlx->mlx, mlx->exit.e_img.img);
	mlx_destroy_image(mlx->mlx, mlx->player.p_img.img);
	mlx_destroy_image(mlx->mlx, mlx->bg_img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
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
