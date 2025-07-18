/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:13:51 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/18 21:30:56 by dgarcez-         ###   ########.fr       */
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

// int	main(void)
// {
// 	int	*array;
// 	int	i;
// 	int	num_elements = 5; 

// 	array = calloc(num_elements, sizeof(int));
// 	i = 0;
// 	write(1, "test", 4);
// 	while (i < num_elements)
// 	{
// 		printf("%d ", array[i]);
// 		i++;
// 	}
// 	printf("aettge\n");
// 	free(array);
// 	return (0);
// }
