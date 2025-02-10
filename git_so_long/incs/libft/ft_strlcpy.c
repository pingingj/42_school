/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:38:36 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/01 13:50:50 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	tam;

	tam = 0;
	i = 0;
	if (src == NULL)
		return (0);
	while (src[tam] != '\0')
		tam++;
	if (size == 0)
		return (tam);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (tam);
}
/*
int	main(void)
{
	char	src[] = "Hello";
	char	dst[6];
	int		lg;

	lg = ft_strlcpy(dst, src, 0);
	printf("Src: %s \n", src);
	printf("Dst: %s \n", dst);
	printf("Length: %d \n", lg);
}
*/
