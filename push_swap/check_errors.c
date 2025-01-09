/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:48:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/03 19:39:09 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nums(char **strings)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (strings == NULL)
		return (0);
	while (strings[i])
	{
		j = 0;
		while (strings[i][j] == ' ')
			j++;
		if (strings[i][j] == '-' || strings[i][j] == '+')
			j++;
		if (strings[i][j] == '\0')
			return (0);
		while (strings[i][j])
		{
			if (!ft_isdigit(strings[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	check_dupes_limits(char **strings)
{
	int	i;
	int	j;

	i = 0;
	while (strings[i])
	{
		j = i + 1;
		while (strings[j])
		{
			if (ft_strcmp(strings[i], strings[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (strings[i])
	{
		if (ft_atol(strings[i]) > INT_MAX || ft_atol(strings[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

char	**error_check(int argc, char **argv)
{
	char	**strings;
	char	*inputs;
	int		i;

	i = 1;
	inputs = NULL;
	if (argc <= 1)
		return (NULL);
	while (argv[i])
	{
		if (check_spaces(argv[i]))
			return (NULL);
		inputs = other_strjoin(inputs, argv[i++]);
		if (inputs == NULL)
			return (free(inputs), NULL);
		inputs = other_strjoin(inputs, " ");
		if (inputs == NULL)
			return (free(inputs), NULL);
	}
	strings = ft_split(inputs, ' ');
	if (strings == NULL)
		return (free(inputs), NULL);
	if (!check_nums(strings) || check_dupes_limits(strings))
		return (free_split(strings), free(inputs), NULL);
	return (free(inputs), strings);
}
