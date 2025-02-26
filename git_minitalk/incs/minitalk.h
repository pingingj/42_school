/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:40:24 by root              #+#    #+#             */
/*   Updated: 2025/02/26 18:19:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H

#include "../incs/libft/libft.h"
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

void	kill_check(pid_t id, int signal);

#endif