/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:06:33 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/15 19:12:48 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent(const char *str, va_list args, int *length)
{
	unsigned long int	ptr;

	if (*str == 'c')
		ft_putchar(va_arg(args, int), length);
	if (*str == 's')
		ft_putstr(va_arg(args, char *), length);
	if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), length);
	if (*str == 'u')
		ft_putunsignednbr(va_arg(args, unsigned int), length);
	if (*str == '%')
		ft_putchar('%', length);
	if (*str == 'x')
		ft_putnbrbase(va_arg(args, unsigned int), "0123456789abcdef", length);
	if (*str == 'X')
		ft_putnbrbigbase(va_arg(args, unsigned int), "0123456789ABCDEF", \
				length);
	if (*str == 'p')
	{
		ptr = (unsigned long int)va_arg(args, void *);
		ft_putptrbase(ptr, "0123456789abcdef", length, 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	length = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ft_percent(str, args, &length);
		}
		else
		{
			write(1, str, 1);
			length++;
		}
		str++;
	}
	va_end(args);
	return (length);
}
/* 
int	main(void)
{
	char			caractere;
	char			*str;
	char			*charnull;
	int				num_max;
	int				num_small;
	int				*p;
	char			*nilp;
	unsigned int	unsignint;
	int				hexa;

	caractere = '*';
	str = "normal string";
	charnull = NULL;
	num_max = INT_MAX;
	num_small = INT_MIN;
	p = &num_max;
	unsignint = -663;
	hexa = -667868;
	int resultado;
	nilp = charnull;teste
	
	ft_printf("abc %0d abc\n", 99);
	printf("abc %0d abc", 99);
} */