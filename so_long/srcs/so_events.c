/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:47:13 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/09 17:06:36 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	player_movement(int keycode, t_game *game)
{
	if (keycode == 'w' && game->map[game->player.pos.y
			- 1][game->player.pos.x] != '1')
	{
		game->player.pos.y -= 1;
		game->moves++;
	}
	if (keycode == 's' && game->map[game->player.pos.y
			+ 1][game->player.pos.x] != '1')
	{
		game->player.pos.y += 1;
		game->moves++;
	}
	if (keycode == 'a' && game->map[game->player.pos.y][game->player.pos.x
		- 1] != '1')
	{
		game->player.pos.x -= 1;
		game->moves++;
	}
	if (keycode == 'd' && game->map[game->player.pos.y][game->player.pos.x
		+ 1] != '1')
	{
		game->player.pos.x += 1;
		game->moves++;
	}
}

void	ft_putmoves(t_game *game, int moves, int position)
{
	int	result;

	result = moves % 10;
	if (moves >= 10)
		ft_putmoves(game, moves / 10, position + 1);
	change_number_bg(game, &game->nums[result], position);
}

void	map_updater(t_game *game, t_player *player)
{
	if (game->moves > 999)
	{
		game->moves = 0;
		change_number_bg(game, &game->nums[0], 2);
		change_number_bg(game, &game->nums[0], 1);
		change_number_bg(game, &game->nums[0], 0);
	}
	ft_putmoves(game, game->moves, 0);
	if (game->map[player->pos.y][player->pos.x] == 'c')
	{
		game->c_amount--;
		game->map[player->pos.y][player->pos.x] = 'C';
		free(game->coin_pos);
		coin_pos(game);
		put_sprites(game, player->pos.x * SPRITE_SZ, player->pos.y * SPRITE_SZ, &game->empty);
	}
	if (game->c_amount == 0)
		put_sprites(game, game->exit.pos.x * SPRITE_SZ, game->exit.pos.y * SPRITE_SZ,
			&game->exit.e_img);
	if (game->map[player->pos.y][player->pos.x] == 'e' && game->c_amount == 0)
		ft_destroy(game);
}
