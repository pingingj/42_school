/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:56:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/10/29 18:19:47 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	big_nb;
	char		digitos;

	big_nb = n;
	if (big_nb < 0)
	{
		big_nb *= -1;
		write(fd, "-", 1);
	}
	if (big_nb >= 10)
		ft_putnbr_fd(big_nb / 10, fd);
	digitos = big_nb % 10 + '0';
	write(fd, &digitos, 1);
}
/*
int	main(void)
{
	ft_putnbr_fd(-5235, 1);
}
*/
