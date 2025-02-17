/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:41:58 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/13 20:11:33 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_header.h"

void	fill_map(char	*ber_file, t_mlx *mlx)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(ber_file, O_RDONLY);
	while (i < mlx->pos.y)
	{
		mlx->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

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
