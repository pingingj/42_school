/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:37:18 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/15 19:13:02 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(long int nb)
{
	int	tamanho;

	tamanho = 0;
	if (nb <= 0)
	{
		tamanho++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		tamanho++;
	}
	return (tamanho);
}

char	*ft_itoa(int n)
{
	long int	big_nb;
	int			tamanho;
	char		*str;

	big_nb = n;
	tamanho = ft_size(big_nb);
	str = (char *)malloc(tamanho * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	if (big_nb == 0)
		str[0] = '0';
	if (big_nb < 0)
	{
		str[0] = '-';
		big_nb = -big_nb;
	}
	str[tamanho] = '\0';
	while (big_nb > 0)
	{
		str[--tamanho] = (big_nb % 10) + '0';
		big_nb = big_nb / 10;
	}
	return (str);
}

/* int	main(void)
{
	char	*result;

	result = ft_itoa(0);
	printf("%s", result);
} */
