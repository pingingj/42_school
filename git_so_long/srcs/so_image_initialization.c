/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_image_initialization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:11:46 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/17 16:24:39 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	img_init(t_mlx *mlx, char *filename, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx->mlx,
		filename, &img->bits_per_pixel,
		&img->line_length);
	img->addr = mlx_get_data_addr(img->img,
		&img->bits_per_pixel,
		&img->line_length,
		&img->endian);
}

void	set_imgs(t_mlx *mlx)
{
	mlx->bg_img.img = mlx_new_image(mlx->mlx, mlx->pos.x * 96, mlx->pos.y
			* 96 + 216);
	mlx->bg_img.addr = mlx_get_data_addr(mlx->bg_img.img,
			&mlx->bg_img.bits_per_pixel,
			&mlx->bg_img.line_length,
			&mlx->bg_img.endian);
	img_init(mlx, "assets/wall.xpm", &mlx->wall);
	img_init(mlx, "assets/frame.xpm", &mlx->frame);
	img_init(mlx, "assets/smoll.xpm", &mlx->player.p_img);
	img_init(mlx, "assets/smoll_mirror.xpm", &mlx->player_mirror);
	img_init(mlx, "assets/exit.xpm", &mlx->exit.e_img);
	img_init(mlx, "assets/exit_notreached.xpm", &mlx->not_exit);
	img_init(mlx, "assets/empty.xpm", &mlx->empty);
	img_init(mlx, "assets/coin.xpm", &mlx->coins.coin);
	img_init(mlx, "assets/first_coin.xpm", &mlx->coins.first_coin);
	img_init(mlx, "assets/second_coin.xpm", &mlx->coins.second_coin);
	img_init(mlx, "assets/third_coin.xpm", &mlx->coins.third_coin);
	img_init(mlx, "assets/fourth_coin.xpm", &mlx->coins.fourth_coin);
	img_init(mlx, "assets/last_coin.xpm", &mlx->coins.last_coin);
}
