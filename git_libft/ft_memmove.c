/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:44:01 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/04 17:45:28 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destp;
	const unsigned char	*srcp;

	destp = (unsigned char *)dest;
	srcp = (const unsigned char *)src;
	i = 0;
	if (destp < srcp)
	{
		while (i < n)
		{
			destp[i] = srcp[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			destp[i - 1] = srcp[i - 1];
			i--;
		}
	}
	return (dest);
}
/*  int	main(void)
{
	char str[] = "Hello, World!";
    
	printf("%s\n", str);
    ft_memmove(str + 7, str, 8);
    printf("Result: %s\n", str);
}  */