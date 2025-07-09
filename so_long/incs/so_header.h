/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:20:39 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/09 16:59:52 by dgarcez-         ###   ########.fr       */
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

#define SPRITE_SZ 96
#define COUNTER_H 152
#define COUNTER_W 288
#define NUM_H	  101
#define NUM_W	  42

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

typedef struct s_game
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
	t_img		nums[10];
	t_anims		coins;
	t_pos		*coin_pos;
	int			i;
	int			c_amount;
	void		*mlx;
	void		*win;
	int			moves;
}				t_game;

//----------------------------making map-----------------------------//
void			fill_map(char *ber_file, t_game *mlx);
bool			get_player(t_game *map);
bool			get_exit(t_game *map);
int				make_collectible(t_game *map);
void			print_map(t_game map);
bool			check_map(t_game map);
void			pixel_put(t_img *img, int x, int y, int color);
unsigned int				pixel_get(t_img *data, int x, int y);
void			print_errors(t_game *mlx, int error);

//----------------------------map generation-------------------------//
void			set_imgs(t_game *mlx);
void			player_dir_address(t_game *mlx);
void			set_addresses(t_game *mlx);
void			set_imgs_animations(t_game *mlx);
void			set_animations_addresses(t_game *mlx);
void			put_map(t_game *mlx, char **map);
void			put_sprites(t_game *mlx, int x, int y, t_img *img);
void			change_number_bg(t_game *game, t_img *img, int size);

//----------------------------map events----------------------------//
void			player_movement(int keycode, t_game *mlx);
void			map_updater(t_game *mlx, t_player *player);

//----------------------------animation-----------------------------//
void			coin_pos(t_game *mlx);
int				animation(t_game *mlx);

//----------------------------map destruction muahahaa--------------//
int				ft_destroy(t_game *mlx);
void			free_map(t_game *map);
#endif