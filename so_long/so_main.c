/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:41:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/30 23:47:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_header.h"

t_map	make_map(char *ber_file, int fd)
{
	t_map	map;
	char	*temp;
	int		i;

	i = 0;
	map.pos.x = 0;
	map.pos.y = 0;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		map.pos.y++;
		free(temp);
		temp = get_next_line(fd);
	}
	map.map = malloc(sizeof(char *) * map.pos.y);
	close(fd);
	fd = open(ber_file, O_RDONLY);
	while (i < map.pos.y)
	{
		map.map[i] = get_next_line(fd);
		i++;
	}
	map.pos.x = ft_strlen(map.map[0]);
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
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
//     void *mlx;
//     void *mlx_win;

//     mlx = mlx_init();  // Initialize the mlx library
//     if (!mlx)
//     {
//         fprintf(stderr, "mlx_init() failed\n");
//         return (1);
//     }

//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");  // Create a window
//     if (!mlx_win)
//     {
//         fprintf(stderr, "mlx_new_window() failed\n");
//         return (1);
//     }

//     mlx_loop(mlx);  // Pass the mlx pointer to the event loop (it manages the window)

//     return (0);
// }
	int		fd;
	t_map	map;

	fd = open(argv[1], O_RDONLY);
	if (fd < 3 || argc > 2 \
		||ft_strncmp (argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	map = make_map(argv[1], fd);
	map.collectible = make_collectible(&map);
	if (!get_player(&map) || map.collectible == NULL || !get_exit(&map) \
		|| !check_map(map))
	{
		ft_printf("Efrror\n");
		free_map(&map);
		return (1);
	}
	print_map(map);
	free_map(&map);
	return (0);
}