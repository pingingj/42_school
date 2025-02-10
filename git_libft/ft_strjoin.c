/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:54:52 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/05 11:39:51 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*joined;
	size_t	n;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(size * sizeof(char) + 1);
	if (joined == NULL)
		return (NULL);
	n = ft_strlen(s1);
	while (i < n)
	{
		joined[i] = s1[i];
		i++;
	}
	while (i < size)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

/* int	main(void)
{
	char	*s1;
	char	*s2;
	char	*joined;

	s1 = "pen pineapple";
	s2 = " apple pen";
	joined = ft_strjoin(s1, s2);
	printf("%s", joined);
	free(joined);
} */