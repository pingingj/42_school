/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:09:16 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/17 14:50:08 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_header.h"

bool	get_player(t_map *map)
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

bool	get_exit(t_map *map)
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

t_collect	*get_collectibles(int amount, t_map *map)
{
	t_collect	*collect;
	int			i;
	int			j;
	int			index;

	collect = malloc(sizeof(t_collect) * amount);
	index = 0;
	i = 0;
	while (i < map->pos.y)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
			{
				collect[index].collected = false;
				collect[index].pos.x = j;
				collect[index].pos.y = i;
				index++;
			}
			j++;
		}
		i++;
	}
	return (collect);
}

t_collect	*make_collectible(t_map *map)
{
	int			i;
	int			j;
	t_collect	*collect;
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
	if (amount == 0)
		return (NULL);
	collect = get_collectibles(amount, map);
	collect->amount = amount;
	return (collect);
}

void	print_map(t_map map)
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
	while (i < map.collectible->amount)
	{
		printf("COLLECTIBLE positions i = %d, X = %d, Y = %d\n", i,
			map.collectible[i].pos.x, map.collectible[i].pos.y);
		i++;
	}
	printf("EXIT position: X = %d, Y = %d\n", map.exit.pos.x, map.exit.pos.y);
}
