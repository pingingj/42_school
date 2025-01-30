/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:20:39 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/30 19:26:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_HEADER_H
# define SO_HEADER_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pos
{
	bool		exists;
	int			x;
	int			y;
}				t_pos;

typedef struct s_collect
{
	bool		collected;
	int			amount;
	t_pos		pos;
}				t_collect;

typedef struct s_player
{
	void		*img;
	t_pos		pos;
}				t_player;

typedef struct s_exit
{
	bool		reached;
	t_pos		pos;
}				t_exit;

typedef struct s_map
{
	char		**map;

	t_exit		exit;
	t_player	player;
	t_collect	*collectible;
	t_pos		pos;
}				t_map;

//----------------------------making map funcs-----------------------//
bool			get_player(t_map *map);
bool			get_exit(t_map *map);
t_collect		*get_collectibles(int amount, t_map *map);
t_collect		*make_collectible(t_map *map);
void			print_map(t_map map);
bool			check_map(t_map map);
#endif