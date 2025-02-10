/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:20:39 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/10 17:56:50 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_HEADER_H
# define SO_HEADER_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>


typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_pos
{
	bool		exists;
	int			x;
	int			y;
}				t_pos;

typedef struct s_player
{
	t_img		p_img;
	t_pos		pos;
}				t_player;

typedef struct s_exit
{
	t_img		e_img;
	bool		reached;
	t_pos		pos;
}				t_exit;

typedef struct s_mlx
{
	char		**map;
	t_exit		exit;
	t_img		not_exit;
	t_player	player;
	t_img		collectible;
	t_img		floor;
	t_img		wall;
	t_pos		pos;
	int			c_amount;
	void		*mlx;
	void		*win;
	t_img		bg_img;
	int			moves;
}				t_mlx;
//----------------------------making map-----------------------------//
bool			get_player(t_mlx *map);
bool			get_exit(t_mlx *map);
int				make_collectible(t_mlx *map);
void			print_map(t_mlx map);
bool			check_map(t_mlx map);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				pixel_get(t_img *data, int x, int y);

//----------------------------map generation-------------------------//
void		set_imgs(t_mlx *mlx);
void		set_addresses(t_mlx *mlx);
void		put_map(t_mlx *mlx, char **map);

//----------------------------map events----------------------------//
void	player_movement(int	keycode, t_mlx *mlx);

//----------------------------map destruction muahahaa--------------//
int			ft_destroy(t_mlx *mlx);
void		free_map(t_mlx *map);
#endif