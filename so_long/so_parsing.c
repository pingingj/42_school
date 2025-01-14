/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:41:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/14 20:33:57 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_header.h"

t_map	*make_map(int fd)
{
	t_map	*map;
	char	*temp;
	int		i;

	temp = "";
	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->pos.x = 0;
	map->pos.y = 0;
	map->collectible.amount = 0;
	while ((temp = get_next_line(fd)) != NULL)
	{
		map->pos.y++;
		free(temp);
	}
	map->map = malloc(sizeof(char *) * map->pos.y);
	close(fd);
	fd = open("map.txt", O_RDONLY);
	while (i < map->pos.y)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	map->pos.x = ft_strlen(map->map[0]);
	return (map);
}

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

bool	get_collectible(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->pos.y)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
			{
				map->collectible.amount++;
				map->collectible.collected = false;
			}
			j++;
		}
		i++;
	}
	if (map->collectible.amount == 0)
		return (false);
	return (true);
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
	printf("PLAYER positions X = %d, Y = %d\n", map.player.pos.x, \
			map.player.pos.y);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->pos.y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

int	main(void)
{
	int fd;
	t_map *map;
	fd = open("map.txt", O_RDONLY);
	map = make_map(fd);
	if (!get_player(map) || !get_collectible(map) || !get_exit(map))
	{
		ft_printf("Error\n");
		free_map(map);
		return (1);
	}
	print_map(*map);
	free_map(map);
	return (0);
}