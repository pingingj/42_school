/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:54:07 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/10/28 16:10:40 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char	*str)
{
	size_t	tamanho;

	tamanho = 0;
	while (*str != '\0')
	{
		tamanho++;
		str++;
	}
	return (tamanho);
}

/*
int	main(void)
{
	int tam;

	tam = ft_strlen("1281qwf0");
	printf("%d", tam);
}
*/
