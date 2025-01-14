/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:10:24 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/04 17:51:18 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_confirm_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		length;
	char	*strtrim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = 0;
	length = ft_strlen(s1);
	while (s1[i] != '\0' && ft_confirm_char(s1[i], set))
		i++;
	while (length > i && ft_confirm_char(s1[length - 1], set))
		length--;
	strtrim = (char *)malloc(sizeof(char) * (length - i + 1));
	if (strtrim == NULL)
		return (NULL);
	while ((i + j) < length)
	{
		strtrim[j] = s1[i + j];
		j++;
	}
	strtrim[j] = '\0';
	return (strtrim);
}
/* 
int	main(void)
{
	char	*s1;
	char	*trimmed;

	s1 = "atetexxxteathis is so teaxxx";
	trimmed = ft_strtrim(s1, "xtea");
	printf("%s", trimmed);
	free (trimmed);
} */
