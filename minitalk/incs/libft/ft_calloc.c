/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:13:51 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/24 11:45:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;

	if (nmemb != 0 && size > (size_t)(-1) / nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
/*
int	main(void)
{
	int	*array;
	int	i;
	int	num_elements = -5; 

	array = calloc(num_elements, sizeof(int));
	i = 0;
	while (i < num_elements)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	free(array);
	return (0);
}
*/
