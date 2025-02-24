/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:24:19 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/14 17:04:25 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_strjoin_2(NULL, buff);
	if (!str)
		return (NULL);
	movebuff(buff);
	bytes_read = 1;
	while (!(ft_withnewline(str)))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		str = ft_strjoin_2(str, buff);
		if (!str)
			return (NULL);
		movebuff(buff);
	}
	if (!str[0] || bytes_read < 0)
		return (free(str), NULL);
	return (str);
}

/* int	main(void)
{
	int fd;
	int i;
	char *str;

	str = "";
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str != NULL)
			printf("%s", str);
		free(str);
	}
	return (0);
}
 */