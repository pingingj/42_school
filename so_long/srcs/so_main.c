/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:41:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/09 16:34:27 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

char	**make_map(char *ber_file, int fd, t_game *game)
{
	char	*temp;

	game->pos.x = 0;
	game->pos.y = 0;
	temp = get_next_line(fd);
	if (temp == NULL)
		return (NULL);
	while (temp != NULL)
	{
		game->pos.y++;
		free(temp);
		temp = get_next_line(fd);
	}
	game->map = malloc(sizeof(char *) * game->pos.y);
	if (game->map == NULL)
		return (NULL);
	close(fd);
	fill_map(ber_file, game);
	game->pos.x = ft_strlen(game->map[0]) - 1;
	return (game->map);
}

t_game	parse(char *filename, int fd)
{
	t_game	game;

	if (fd < 3 || ft_strncmp(filename + ft_strlen(filename) - 4, ".ber",
			4) != 0)
		print_errors(&game, 2);
	game.map = make_map(filename, fd, &game);
	if (game.map == NULL)
		print_errors(&game, 3);
	game.c_amount = make_collectible(&game);
	if (!get_player(&game) || game.c_amount == 0 || !get_exit(&game)
		|| !check_map(game))
		print_errors(&game, 4);
	if (game.pos.x > 20 || game.pos.y > 9)
		print_errors(&game, 5);
	coin_pos(&game);
	if (game.coin_pos == NULL)
		print_errors(&game, 6);
	return (game);
}

int	keys(int keycode, t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	if (keycode == 65307)
		ft_destroy(game);
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		player_movement(keycode, game);
	map_updater(game, &game->player);
	mlx_put_image_to_window(game->mlx, game->win, game->bg_img.img, 0, 0);
	if (keycode == 'a' || (keycode == 'w' && game->player.dir == 1)
		|| (keycode == 's' && game->player.dir == 1))
		game->player.dir = 1;
	else if (keycode == 'd')
		game->player.dir = 0;
	if (game->player.dir == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->player_mirror.img,
			game->player.pos.x * SPRITE_SZ, game->player.pos.y * SPRITE_SZ);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->player.p_img.img,
			game->player.pos.x * SPRITE_SZ, game->player.pos.y * SPRITE_SZ);
	ft_printf("moves done: %d\n", game->moves);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
	{
		print_errors(&game, 1);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	game = parse(argv[1], fd);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.pos.x * SPRITE_SZ, game.pos.y * SPRITE_SZ + COUNTER_H,
			"so_longing");
	set_imgs(&game);
	put_map(&game, game.map);
	mlx_hook(game.win, 17, 0, ft_destroy, &game);
	mlx_hook(game.win, 02, 1L << 0, keys, &game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_loop(game.mlx);
	return (0);
}
