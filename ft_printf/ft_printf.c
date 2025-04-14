/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:06:33 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/11 17:58:41 by dgarcez-         ###   ########.fr       */
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
		ft_putnbrbigbase(va_arg(args, unsigned int), "0123456789ABCDEF",
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
	nilp = charnull;
	
	resultado = printf(NULL);
	printf("%d\n", resultado);
	
	resultado = ft_printf(NULL);
	printf("%d\n\n", resultado);
	
	resultado = ft_printf("ft_printf %%s: %s\n", charnull);
	ft_printf("caracteres imprimidos %d\n\n", resultado);
	
	resultado = printf("printf %%s: %s\n", charnull);
	printf("caracteres imprimidos %d\n\n", resultado);
	
	ft_printf("ft_printf %%s: %s\n", str);
	printf("printf %%s:%s\n\n", str);
	
	ft_printf("ft_printf %%c: %c\n", caractere);
	printf("printf %%c: %c\n\n", caractere);
	
	ft_printf("ft_printf %%d: %d\n", num_max);
	printf("printf %%d: %d\n\n", num_max);
	
	ft_printf("ft_printf %%u: %u\n", unsignint);
	printf("printf %%u: %u\n\n", unsignint);
	
	ft_printf("ft_printf %%i: %i\n", num_small);
	printf("printf %%i: %i\n\n", num_small);
	
	ft_printf("ft_printf %%p: %p \n", charnull);
	printf("printf %%p: %p\n\n", charnull);
	
	ft_printf("ft_printf hexa: %x\n", hexa);
	printf("printf hexa: %x\n\n", hexa);

	ft_printf("ft_printf hexa: %X\n", hexa);
	printf("printf hexa: %X\n\n", hexa);
	
	resultado = printf("%p\n", nilp);
	printf("caracteres imprimidos %d\n", resultado);
	
	resultado = ft_printf("%p\n", nilp);
	ft_printf("caracteres imprimidos %d\n", resultado);
} */