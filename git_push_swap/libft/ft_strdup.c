/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:09:51 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/04 16:49:45 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (buffer == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
/*
int	main(void)
{
	char	*src;
	char	*duped;
	char	*duped2;

	
	src = "-testeo45";
	duped = ft_strdup(src);
	printf("%s", duped);
	free (duped);
	src = "-testeo45";
	duped2 = strdup(src);
	printf("%s", duped2);
	free (duped);
}
*/
