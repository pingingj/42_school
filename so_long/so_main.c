/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:41:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/15 19:55:24 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_header.h"

t_map	*make_map(int fd)
{
	t_map	*map;
	char	*temp;
	int		i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->pos.x = 0;
	map->pos.y = 0;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		map->pos.y++;
		free(temp);
		temp = get_next_line(fd);
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

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	free(map->collectible);
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
	int		fd;
	t_map	*map;

	fd = open("map.txt", O_RDONLY);
	map = make_map(fd);
	map->collectible = make_collectible(map);
	if (!get_player(map) || map->collectible == NULL || !get_exit(map) \
		|| !check_map(*map))
	{
		ft_printf("Error\n");
		free_map(map);
		return (1);
	}
	print_map(*map);
	free_map(map);
	return (0);
}
