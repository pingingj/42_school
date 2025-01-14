/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:00:43 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/10/28 15:59:04 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destp;
	const unsigned char	*srcp;

	destp = (unsigned char *)dest;
	srcp = (const unsigned char *)src;
	while (n > 0)
	{
		*destp = *srcp;
		destp++;
		srcp++;
		n--;
	}
	return (dest);
}
/*
int	main(void)
{
	const char	src[50] = "Tutorialspoint";
	char		dest[50];

	strcpy(dest,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, 9);
	printf("After memcpy dest = %s\n", dest);
	return(0);
}
*/