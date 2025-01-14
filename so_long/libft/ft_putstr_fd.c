/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:45:54 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/04 11:11:39 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != 0)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
int	main(void)
{
	ft_putstr_fd("Hello, World!\n", -5123);
	ft_putstr_fd(NULL, 1);
	return (0);
}
*/