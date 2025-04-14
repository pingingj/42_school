/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:40:24 by root              #+#    #+#             */
/*   Updated: 2025/03/05 00:05:57 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../incs/libft/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

void	kill_check(pid_t id, int signal);

#endif