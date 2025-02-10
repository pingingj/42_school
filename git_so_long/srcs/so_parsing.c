/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:09:16 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/10 17:54:03 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

bool	get_player(t_mlx *map)
{
	int	i;
	int	j;

	i = 0;
	map->player.pos.exists = false;
	while (i < map->pos.y)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				if (map->player.pos.exists == true)
					return (false);
				map->player.pos.x = j;
				map->player.pos.y = i;
				map->player.pos.exists = true;
			}
			j++;
		}
		i++;
	}
	if (map->player.pos.exists == false)
		return (false);
	return (true);
}

bool	get_exit(t_mlx *map)
{
	int	i;
	int	j;

	i = 0;
	map->exit.pos.exists = false;
	while (i < map->pos.y)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
			{
				if (map->exit.pos.exists == true)
					return (false);
				map->exit.pos.x = j;
				map->exit.pos.y = i;
				map->exit.pos.exists = true;
			}
			j++;
		}
		i++;
	}
	if (map->exit.pos.exists == false)
		return (false);
	return (true);
}

int	make_collectible(t_mlx *map)
{
	int			i;
	int			j;
	int			amount;

	amount = 0;
	i = 0;
	while (i < map->pos.y)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				amount++;
			j++;
		}
		i++;
	}
	return (amount);
}

void	print_map(t_mlx map)
{
	int	i;

	i = 0;
	while (i < map.pos.y)
	{
		printf("i = %d %s", i, map.map[i]);
		i++;
	}
	printf("\nX = %d Y = %d\n", map.pos.x, map.pos.y);
	printf("PLAYER positions X = %d, Y = %d\n", map.player.pos.x,
		map.player.pos.y);
	i = 0;
	ft_printf("COLLETIBLE AMOUNT = %d\n", map.c_amount);
	printf("EXIT position: X = %d, Y = %d\n", map.exit.pos.x, map.exit.pos.y);
}
