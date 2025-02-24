/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:54:52 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/02/24 17:56:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	i = -1;
	j = 0;
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char) + 1);
	if (joined == NULL)
		return (NULL);
	while (++i < ft_strlen(s1))
		joined[i] = s1[i];
	while (s2[j] != '\0')
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