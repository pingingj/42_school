/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:41:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/10 17:53:05 by dgarcez-         ###   ########.fr       */
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
	mlx->map = malloc(sizeof(char *) * mlx->pos.y);
	close(fd);
	fd = open(ber_file, O_RDONLY);
	while (i < mlx->pos.y)
	{
		mlx->map[i] = get_next_line(fd);
		i++;
	}
	mlx->pos.x = ft_strlen(mlx->map[0]);
	return (mlx->map);
}

t_mlx	parse(char *filename, int fd)
{
	t_mlx	mlx;

	if (fd < 3 || ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4)
		!= 0)
	{
		ft_printf("Error\nFile is not in the correct format");
		exit (1);
	}
	mlx.map = make_map(filename, fd, &mlx);
	if (mlx.map == NULL)
	{
		ft_printf("Error\nNo map provided Bruh\n");
		exit(1);
	}
	mlx.c_amount = make_collectible(&mlx);
	if (!get_player(&mlx) || mlx.c_amount == 0 || !get_exit(&mlx)
		|| !check_map(mlx))
	{
		ft_printf("Error\nWhile making map, might be invalid\n");
		free_map(&mlx);
		exit(1);
	}
	print_map(mlx);
	return (mlx);
}

int	win_close(int keycode, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	if (keycode == 65307)
		ft_destroy(mlx);
	player_movement(keycode, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg_img.img, 0, 0);
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
	mlx.win = mlx_new_window(mlx.mlx, (mlx.pos.x - 1) * 96, mlx.pos.y * 96,
			"Hello world!");
	set_imgs(&mlx);
	set_addresses(&mlx);
	mlx.moves = 0;
	put_map(&mlx, mlx.map);
	mlx_hook(mlx.win, 17, 0, ft_destroy, &mlx);
	mlx_key_hook(mlx.win, win_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
