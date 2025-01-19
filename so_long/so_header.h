/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:20:39 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/17 14:54:05 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_HEADER_H
# define SO_HEADER_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

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
void			flood_map(t_map	*map, int	x, int	y);
bool			check_flood(t_map map);
#endif