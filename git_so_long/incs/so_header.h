/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:20:39 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/17 16:18:16 by dgarcez-         ###   ########.fr       */
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
# include <sys/time.h>

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
	int			dir;
	t_img		p_img;
	t_pos		pos;
}				t_player;

typedef struct s_exit
{
	t_img		e_img;
	bool		reached;
	t_pos		pos;
}				t_exit;

typedef struct s_anims
{
	t_img		coin;
	t_img		first_coin;
	t_img		second_coin;
	t_img		third_coin;
	t_img		fourth_coin;
	t_img		last_coin;
}				t_anims;

typedef struct s_mlx
{
	char		**map;
	t_pos		pos;
	t_player	player;
	t_img		player_mirror;
	t_exit		exit;
	t_img		not_exit;
	t_img		floor;
	t_img		wall;
	t_img		empty;
	t_img		bg_img;
	t_img		frame;
	t_anims		coins;
	t_pos		*coin_pos;
	int			i;
	int			c_amount;
	void		*mlx;
	void		*win;
	int			moves;
}				t_mlx;

//----------------------------making map-----------------------------//
void			fill_map(char	*ber_file, t_mlx *mlx);
bool			get_player(t_mlx *map);
bool			get_exit(t_mlx *map);
int				make_collectible(t_mlx *map);
void			print_map(t_mlx map);
bool			check_map(t_mlx map);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				pixel_get(t_img *data, int x, int y);

//----------------------------map generation-------------------------//
void			set_imgs(t_mlx *mlx);
void			player_dir_address(t_mlx *mlx);
void			set_addresses(t_mlx *mlx);
void			set_imgs_animations(t_mlx *mlx);
void			set_animations_addresses(t_mlx *mlx);
void			put_map(t_mlx *mlx, char **map);
void			put_sprites(t_mlx *mlx, int x, int y, t_img *img);

//----------------------------map events----------------------------//
void			player_movement(int keycode, t_mlx *mlx);
void			map_updater(t_mlx *mlx, t_player *player);

//----------------------------animation-----------------------------//
void			coin_pos(t_mlx	*mlx);
int				animation(t_mlx	*mlx);

//----------------------------map destruction muahahaa--------------//
int				ft_destroy(t_mlx *mlx);
void			free_map(t_mlx *map);
#endif