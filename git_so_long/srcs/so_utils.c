/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:41:58 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/16 21:50:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	img_init(t_mlx *mlx, char *filename, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx->mlx,
		filename, &img.bits_per_pixel,
		&img.line_length);
	if(img->img == NULL)
	{
		ft_printf("Error\n Unable to load image");
		exit(0);
	}
	img.addr = mlx_get_data_addr(img->img,
		&img.bits_per_pixel,
		&img.line_length,
		&img.endian);
}

void	set_imgs(t_mlx *mlx)
{
	mlx->player.p_img.img = mlx_xpm_file_to_image(mlx->mlx,
			"assets/smoll.xpm", &mlx->player.p_img.bits_per_pixel,
			&mlx->player.p_img.line_length);
	mlx->collectible.img = mlx_xpm_file_to_image(mlx->mlx,
			"assets/coin.xpm",
			&mlx->collectible.bits_per_pixel,
			&mlx->collectible.line_length);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx,
			"assets/wall.xpm",
			&mlx->wall.bits_per_pixel,
			&mlx->wall.line_length);
	mlx->exit.e_img.img = mlx_xpm_file_to_image(mlx->mlx,
			"assets/exit.xpm",
			&mlx->exit.e_img.bits_per_pixel,
			&mlx->exit.e_img.line_length);
	mlx->not_exit.img = mlx_xpm_file_to_image(mlx->mlx,
			"assets/exit_notreached.xpm",
			&mlx->not_exit.bits_per_pixel,
			&mlx->not_exit.line_length);
	mlx->bg_img.img = mlx_new_image(mlx->mlx, (mlx->pos.x - 1) * 96, mlx->pos.y
			* 96);
}

void	set_addresses(t_mlx *mlx)
{
	mlx->player.p_img.addr = mlx_get_data_addr(mlx->player.p_img.img,
			&mlx->player.p_img.bits_per_pixel,
			&mlx->player.p_img.line_length,
			&mlx->player.p_img.endian);
	mlx->collectible.addr = mlx_get_data_addr(mlx->collectible.img,
			&mlx->collectible.bits_per_pixel,
			&mlx->collectible.line_length,
			&mlx->collectible.endian);
	mlx->wall.addr = mlx_get_data_addr(mlx->wall.img,
			&mlx->wall.bits_per_pixel,
			&mlx->wall.line_length,
			&mlx->wall.endian);
	mlx->exit.e_img.addr = mlx_get_data_addr(mlx->exit.e_img.img,
			&mlx->exit.e_img.bits_per_pixel,
			&mlx->exit.e_img.line_length,
			&mlx->exit.e_img.endian);
	mlx->not_exit.addr = mlx_get_data_addr(mlx->not_exit.img,
			&mlx->not_exit.bits_per_pixel,
			&mlx->not_exit.line_length,
			&mlx->not_exit.endian);
	mlx->bg_img.addr = mlx_get_data_addr(mlx->bg_img.img,
			&mlx->bg_img.bits_per_pixel,
			&mlx->bg_img.line_length,
			&mlx->bg_img.endian);
}
