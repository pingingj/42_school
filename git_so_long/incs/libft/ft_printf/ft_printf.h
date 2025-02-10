/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:28:13 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/11 17:28:26 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

/*  __attribute__((format(printf, 1, 2))); */

void	ft_putchar(int c, int *length);

void	ft_putstr(char *str, int *length);

void	ft_putnbr(int nb, int *length);

void	ft_putunsignednbr(unsigned int nb, int *length);

void	ft_putnbrbase(unsigned int nb, const char *base, int *length);

void	ft_putnbrbigbase(unsigned int nb, const char *base, int *length);

void	ft_putptrbase(unsigned long int ptr, const char *base, int *length,
			int check);
#endif