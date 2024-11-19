/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:22:12 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/05 11:20:11 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*malloc_words(const char **s, char c)
{
	int			length;
	char		*word;
	const char	*str;

	length = 0;
	while (**s != '\0' && **s == c)
		(*s)++;
	str = (*s);
	while (**s != '\0' && **s != c)
	{
		length++;
		(*s)++;
	}
	word = malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, str, length + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	strings = malloc(sizeof(char *) * (words + 1));
	if (strings == NULL)
		return (NULL);
	strings[words] = 0;
	i = 0;
	while (i < words)
	{
		strings[i] = malloc_words(&s, c);
		if (strings[i] == NULL)
		{
			while (i--)
				free(strings[i]);
			free(strings);
			return (NULL);
		}
		i++;
	}
	return (strings);
}
/* int	main(void)
{
	char	**tab;
	int		i;
	
	i = 0;
	tab = ft_split("  hlelo..5.3..42.....", '.');
	while(tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
} */