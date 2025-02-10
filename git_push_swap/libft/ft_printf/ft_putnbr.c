/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:24:34 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/11 16:58:38 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *length)
{
	long int	big_nb;
	char		digito;

	big_nb = nb;
	if (big_nb < 0)
	{
		ft_putchar('-', length);
		big_nb = -big_nb;
	}
	if (big_nb >= 10)
		ft_putnbr(big_nb / 10, length);
	digito = (big_nb % 10) + '0';
	ft_putchar(digito, length);
}

void	ft_putunsignednbr(unsigned int nb, int *length)
{
	char	digito;

	if (nb >= 10)
		ft_putnbr(nb / 10, length);
	digito = (nb % 10) + '0';
	ft_putchar(digito, length);
}

void	ft_putnbrbase(unsigned int nb, const char *base, int *length)
{
	char	digito;

	if (nb >= 16)
		ft_putnbrbase(nb / 16, base, length);
	digito = base[nb % 16];
	ft_putchar(digito, length);
}

void	ft_putnbrbigbase(unsigned int nb, const char *base, int *length)
{
	char	digito;

	if (nb >= 16)
		ft_putnbrbase(nb / 16, base, length);
	digito = base[nb % 16];
	ft_putchar(digito, length);
}

void	ft_putptrbase(unsigned long int ptr, const char *base, int *length,
		int check)
{
	char	digito;

	digito = 0;
	if (ptr == 0)
	{
		ft_putstr("(nil)", length);
		return ;
	}
	if (check == 1)
	{
		ft_putstr("0x", length);
		check = 0;
	}
	if (ptr >= 16)
		ft_putptrbase(ptr / 16, base, length, check);
	digito = base[ptr % 16];
	ft_putchar(digito, length);
}
