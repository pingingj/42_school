/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:35:25 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/11 15:07:26 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *length)
{
	write(1, &c, 1);
	*length += 1;
}

void	ft_putstr(char *str, int *length)
{
	if (!str)
		str = "(null)";
	while (*str != '\0')
	{
		ft_putchar(*str, length);
		str++;
	}
}
