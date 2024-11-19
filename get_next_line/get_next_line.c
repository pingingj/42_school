/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:24:19 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/19 16:27:21 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = 0;
	str = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (i <= BUFFER_SIZE)
			buffer[i++] = '\0';
		return (NULL);
	}
	while (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0))
	{
		str = ft_strjoin(str, buffer);
		if (str == NULL)
		{
			free(str);
			return (NULL);
		}
		movebuff(buffer);
		if (str[ft_linelen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}

/* int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	str = "";
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while(str != NULL)
	{
		str = get_next_line(fd);
		if (str)
			printf("line: %s", str);
		free (str);
	}
	close(fd);
	return (0);
}
 */