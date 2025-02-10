/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:28:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/01 13:52:28 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	str_length;
	char	*substr;

	i = start;
	j = 0;
	str_length = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= str_length)
		return (ft_strdup(""));
	if (len + start > str_length)
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (s[i] != '\0' && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
/*
int	main(void)
{
	char	*str;
	char	*substr;

	str = "0123456789";
	substr = ft_substr(str, 9, 10);
	printf("%s", substr);
	free (substr);
}
*/
