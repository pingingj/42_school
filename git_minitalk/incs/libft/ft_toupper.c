/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:36:24 by marvin            #+#    #+#             */
/*   Updated: 2024/10/28 15:59:54 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
/*
int	main(void)
{
	char	letra;
	int		b;

	letra = 'z';
	printf("%c", letra);
	b = ft_toupper(letra);
	//int t = toupper(letra);
	printf("%c", b);
}
*/