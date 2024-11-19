/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:24:15 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/19 16:19:06 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linelen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	joined = (char *)malloc(ft_linelen(s1) + ft_linelen(s2) * sizeof(char) + 1);
	if (joined == NULL)
		return (free(joined), NULL);
	while (s1 && s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		joined[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		joined[i + j++] = '\n';
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}

void	movebuff(char *buff)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i] != '\0')
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
		buff[j++] = '\0';
}
