/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:41:30 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/09 16:28:10 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	destroy_nums(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		mlx_destroy_image(game->mlx, game->nums[i].img);
		i++;
	}	
}

int	ft_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->coins.coin.img);
	mlx_destroy_image(game->mlx, game->coins.first_coin.img);
	mlx_destroy_image(game->mlx, game->coins.second_coin.img);
	mlx_destroy_image(game->mlx, game->coins.third_coin.img);
	mlx_destroy_image(game->mlx, game->coins.fourth_coin.img);
	mlx_destroy_image(game->mlx, game->coins.last_coin.img);
	mlx_destroy_image(game->mlx, game->not_exit.img);
	mlx_destroy_image(game->mlx, game->exit.e_img.img);
	mlx_destroy_image(game->mlx, game->empty.img);
	mlx_destroy_image(game->mlx, game->player_mirror.img);
	mlx_destroy_image(game->mlx, game->player.p_img.img);
	mlx_destroy_image(game->mlx, game->frame.img);
	mlx_destroy_image(game->mlx, game->bg_img.img);
	destroy_nums(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->coin_pos);
	free(game->mlx);
	free_map(game);
	exit(0);
}

void	print_errors(t_game *game, int error)
{
	if (error == 1)
		ft_printf("Error\nNo file provided");
	else if (error == 2)
		ft_printf("Error\nFile is not in the correct format");
	else if (error == 3)
		ft_printf("Error\nNo map provided Bruh\n");
	else if (error == 4)
	{
		free_map(game);
		ft_printf("Error\nInvalid Map\n");
	}
	else if (error == 5)
	{
		free_map(game);
		ft_printf("Map, is too big\n");
	}
	else if (error == 6)
	{
		free_map(game);
		ft_printf("Map, is too big\n");
	}
	exit(error);
}

void	free_map(t_game *map)
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
