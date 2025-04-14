/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:52:49 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/04 11:32:30 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	int arr[10];
	int array2[10];
	memset(arr, 7, sizeof(arr));
	memset(array2, 7, sizeof(array2));
	printf("Array 1 after memset(): ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Array 2 after memset(): ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array2[i]);
	}

	ft_bzero(arr, sizeof(arr));
	bzero(array2, sizeof(array2));

	printf("Array 1 after ft_bzero(): ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Array 2 after bzero(): ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array2[i]);
	}
	return (0);
}
*/