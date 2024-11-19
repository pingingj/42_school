/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:54:07 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/05 11:01:43 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}
/*
int	main(void) {
	int arr[10];
	int array2[10];
	ft_memset(arr, 15, sizeof(arr));
	memset(array2, 15, sizeof(array2));
	printf("Array 1 after memset(): ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Array 2 after memset(): ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", array2[i]);
	}
	return (0);
}
*/