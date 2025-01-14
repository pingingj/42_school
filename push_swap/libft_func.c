/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:52:41 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/14 20:35:02 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*other_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	i = -1;
	j = 0;
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char) + 1);
	if (joined == NULL)
		return (free(s1), NULL);
	while (++i < ft_strlen(s1))
		joined[i] = s1[i];
	while (s2[j] != '\0')
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		minus;
	long	result;

	i = 0;
	minus = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -minus;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result > INT_MAX)
			break ;
		i++;
	}
	return (result * minus);
}

void	double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1 && stack_b->size <= 1)
		return ;
	rotate(stack_a, 'a', false);
	rotate(stack_b, 'b', false);
	ft_printf("rr\n");
}

void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1 && stack_b->size <= 1)
		return ;
	reverse_rotate(stack_a, 'a', false);
	reverse_rotate(stack_b, 'b', false);
}
