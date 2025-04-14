/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:01 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/19 16:05:04 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

static bool	check_boarders(t_game map)
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

static void	flood_map(t_game *map, int x, int y)
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
}

static bool	check_flood(t_game map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.pos.y)
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	if (map.map[map.player.pos.y][map.player.pos.x] != 'p')
		return (false);
	if (map.map[map.exit.pos.y][map.exit.pos.x] != 'e')
		return (false);
	return (true);
}

static bool	check_chars(t_game map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.pos.y)
	{
		j = 0;
		while (map.map[i][j] && map.map[i][j] != '\n')
		{
			if (map.map[i][j] != '0' && map.map[i][j] != '1' &&
				map.map[i][j] != 'P' && map.map[i][j] != 'E' &&
				map.map[i][j] != 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map(t_game map)
{
	int		i;
	size_t	size;
	size_t	temp_x;

	temp_x = map.pos.x;
	i = 0;
	while (i < map.pos.y)
	{
		size = ft_strlen(map.map[i]) - 1;
		if (map.map[i][size] != '\n')
			size++;
		if (temp_x != size)
			return (false);
		i++;
	}
	if (!check_chars(map))
		return (false);
	if (!check_boarders(map))
		return (false);
	flood_map(&map, map.player.pos.x, map.player.pos.y);
	if (!check_flood(map))
		return (false);
	return (true);
}
