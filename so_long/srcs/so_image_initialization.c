/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_image_initialization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:11:46 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/19 17:54:59 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	img_init(t_game *game, char *filename, t_img *img)
{
	img->img = mlx_xpm_file_to_image(game->mlx,
			filename, &img->bits_per_pixel,
			&img->line_length);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian);
}

void	set_num_imgs(t_game *game)
{
	img_init(game, "textures/zero.xpm", &game->nums[0]);
	img_init(game, "textures/one.xpm", &game->nums[1]);
	img_init(game, "textures/two.xpm", &game->nums[2]);
	img_init(game, "textures/three.xpm", &game->nums[3]);
	img_init(game, "textures/four.xpm", &game->nums[4]);
	img_init(game, "textures/five.xpm", &game->nums[5]);
	img_init(game, "textures/six.xpm", &game->nums[6]);
	img_init(game, "textures/seven.xpm", &game->nums[7]);
	img_init(game, "textures/eight.xpm", &game->nums[8]);
	img_init(game, "textures/nine.xpm", &game->nums[9]);
}

void	set_imgs(t_game *game)
{
	game->bg_img.img = mlx_new_image(game->mlx, game->pos.x * 96, game->pos.y
			* 96 + 216);
	game->bg_img.addr = mlx_get_data_addr(game->bg_img.img,
			&game->bg_img.bits_per_pixel,
			&game->bg_img.line_length,
			&game->bg_img.endian);
	img_init(game, "textures/wall.xpm", &game->wall);
	img_init(game, "textures/frame.xpm", &game->frame);
	img_init(game, "textures/smoll.xpm", &game->player.p_img);
	img_init(game, "textures/smoll_mirror.xpm", &game->player_mirror);
	img_init(game, "textures/exit.xpm", &game->exit.e_img);
	img_init(game, "textures/exit_notreached.xpm", &game->not_exit);
	img_init(game, "textures/empty.xpm", &game->empty);
	img_init(game, "textures/coin.xpm", &game->coins.coin);
	img_init(game, "textures/first_coin.xpm", &game->coins.first_coin);
	img_init(game, "textures/second_coin.xpm", &game->coins.second_coin);
	img_init(game, "textures/third_coin.xpm", &game->coins.third_coin);
	img_init(game, "textures/fourth_coin.xpm", &game->coins.fourth_coin);
	img_init(game, "textures/last_coin.xpm", &game->coins.last_coin);
	set_num_imgs(game);
}
