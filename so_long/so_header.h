/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:42:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/14 20:34:04 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

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
	t_collect	collectible;
	t_pos		pos;
}				t_map;

#endif