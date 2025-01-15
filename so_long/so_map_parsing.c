/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:01 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/15 20:37:28 by dgarcez-         ###   ########.fr       */
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
