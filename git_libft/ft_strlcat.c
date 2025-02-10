/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:38:37 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/05 11:38:59 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	tam_src;
	unsigned int	tam_dst;

	tam_src = 0;
	tam_dst = 0;
	i = 0;
	while (src[tam_src] != '\0')
		tam_src++;
	while (dst[tam_dst] != '\0')
		tam_dst++;
	if (size <= tam_dst)
		return (tam_src + size);
	while (src[i] != '\0' && tam_dst + i < size - 1)
	{
		dst[i + tam_dst] = src[i];
		i++;
	}
	dst[i + tam_dst] = '\0';
	return (tam_dst + tam_src);
}
/* int	main(void)
{
	char dest[10] = "BBBBBBBBB";
	char * src = (char *)"AAAAAAAAA ";
	size_t tamanho;
	tamanho = ft_strlcat(dest, src, 15);
	printf("tamanho: %zu\n", tamanho);
	printf("string: %s\n", src);
	printf("resultado: %s", dest);
} */