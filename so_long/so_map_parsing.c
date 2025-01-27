/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:01 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/17 14:58:53 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_header.h"

static bool	check_boarders(t_map map)
{
	int		i;
	int		j;
	size_t	size;

	i = 0;
	size = ft_strlen(map.map[i]);
	while (i < map.pos.y)
	{
		j = 0;
		while (map.map[i][j] && map.map[i][j] != '\n')
		{
			if (i == 0 || i == map.pos.y - 1)
			{
				if (map.map[i][j] != '1')
					return (false);
			}
			else if (map.map[i][0] != '1' || map.map[i][size - 2] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	flood_map(t_map *map, int x, int y)
{
	if (map->map[y][x] == '1' || map->map[y][x] == 'o' || map->map[y][x] == 'e'
		|| map->map[y][x] == 'c')
		return ;
	if (map->map[y][x] == '0')
		map->map[y][x] = 'o';
	if (map->map[y][x] == 'P')
		map->map[y][x] = 'p';
	if (map->map[y][x] == 'E')
		map->map[y][x] = 'e';
	if (map->map[y][x] == 'C')
		map->map[y][x] = 'c';
	flood_map(map, x - 1, y);
	flood_map(map, x + 1, y);
	flood_map(map, x, y - 1);
	flood_map(map, x, y + 1);
	return ;
}

bool	check_flood(t_map map)
{
	int	i;

	i = 0;
	while (i < map.collectible->amount)
	{
		if (map.map[map.collectible[i].pos.y][map.collectible[i].pos.x] != 'c')
			return (false);
		i++;
	}
	if (map.map[map.player.pos.y][map.player.pos.x] != 'p')
			return (false);
	if (map.map[map.exit.pos.y][map.exit.pos.x] != 'e')
			return (false);		
	return (true);
}

bool	check_map(t_map map)
{
	int		i;
	size_t	size;
	size_t	temp_x;

	temp_x = map.pos.x;
	i = 0;
	while (i < map.pos.y)
	{
		size = ft_strlen(map.map[i]);
		if (map.map[i][size - 1] != '\n')
			size++;
		if (temp_x != size)
			return (false);
		i++;
	}
	if (!check_boarders(map))
		return (false);
	return (true);
}
