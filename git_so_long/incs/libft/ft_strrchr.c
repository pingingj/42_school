/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:25:59 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 13:27:57 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_pointer;

	last_pointer = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			last_pointer = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last_pointer);
}
/*
int	main(void)
{
	const char	str[] = "this is a test for lil bro";
	char		*resultado;

	resultado = strrchr(str, 'c');
	printf("%s\n", resultado);
}
*/