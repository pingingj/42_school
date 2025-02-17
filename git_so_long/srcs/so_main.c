/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:41:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/17 17:54:53 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

char	**make_map(char *ber_file, int fd, t_mlx *mlx)
{
	char	*temp;
	int		i;

	i = 0;
	mlx->pos.x = 0;
	mlx->pos.y = 0;
	temp = get_next_line(fd);
	if (temp == NULL)
		return (NULL);
	while (temp != NULL)
	{
		mlx->pos.y++;
		free(temp);
		temp = get_next_line(fd);
	}
	mlx->map = malloc(sizeof(char *) * mlx->pos.y + 1);
	if (mlx->map == NULL)
		return (NULL);
	close(fd);
	fill_map(ber_file, mlx);
	mlx->pos.x = ft_strlen(mlx->map[0]) - 1;
	return (mlx->map);
}

void	check_limits(t_mlx mlx)
{
	if (mlx.pos.x > 20 || mlx.pos.y > 9)
	{
		free_map(&mlx);
		ft_printf("Map, is too big\n");
		exit(0);
	}
}

t_mlx	parse(char *filename, int fd)
{
	t_mlx	mlx;

	if (fd < 3 || ft_strncmp(filename + ft_strlen(filename) - 4, ".ber",
			4) != 0)
	{
		ft_printf("Error\nFile is not in the correct format");
		exit(0);
	}
	mlx.map = make_map(filename, fd, &mlx);
	if (mlx.map == NULL)
	{
		ft_printf("Error\nNo map provided Bruh\n");
		exit(0);
	}
	mlx.c_amount = make_collectible(&mlx);
	if (!get_player(&mlx) || mlx.c_amount == 0 || !get_exit(&mlx)
		|| !check_map(mlx))
	{
		ft_printf("Error\nWhile making map, might be invalid\n");
		free_map(&mlx);
		exit(0);
	}
	check_limits(mlx);
	coin_pos(&mlx);
	return (mlx);
}

int	keys(int keycode, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	if (keycode == 65307)
		ft_destroy(mlx);
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		player_movement(keycode, mlx);
	map_updater(mlx, &mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg_img.img, 0, 0);
	if (keycode == 'a' || (keycode == 'w' && mlx->player.dir == 1)
		|| (keycode == 's' && mlx->player.dir == 1))
		mlx->player.dir = 1;
	else if (keycode == 'd')
		mlx->player.dir = 0;
	if (mlx->player.dir == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player_mirror.img,
			mlx->player.pos.x * 96, mlx->player.pos.y * 96);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player.p_img.img,
			mlx->player.pos.x * 96, mlx->player.pos.y * 96);
	ft_printf("moves done: %d\n", mlx->moves);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Error\nNo file provided");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	mlx = parse(argv[1], fd);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.pos.x * 96, mlx.pos.y * 96 + 152,
			"so_longing");
	mlx_clear_window(mlx.mlx, mlx.win);
	set_imgs(&mlx);
	put_map(&mlx, mlx.map);
	mlx_hook(mlx.win, 17, 0, ft_destroy, &mlx);
	mlx_key_hook(mlx.win, keys, &mlx);
	mlx_loop_hook(mlx.mlx, animation, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
