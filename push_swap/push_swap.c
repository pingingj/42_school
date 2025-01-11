/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:38:44 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/11 02:03:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack(char **strings)
{
	int		i;
	t_stack	*stack;
	t_node	*new;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	i = 0;
	new = NULL;
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
	while (strings != NULL && strings[i] != NULL)
	{
		new = ft_nodenew(ft_atoi(strings[i]));
		if (new == NULL)
			return (NULL);
		ft_stackadd_back(stack, new);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	char **strings;
	t_stack *stack_a;
	t_stack *stack_b;

	strings = error_check(argc, argv);
	if (strings != NULL)
	{
		stack_a = make_stack(strings);
		if (stack_a == NULL)
			free_split(strings);
		stack_b = make_stack(NULL);
		sort_stacks(stack_a, stack_b);
		clear_stack(stack_a);
		clear_stack(stack_b);
		free_split(strings);
		return (0);
	}
	ft_printf("Error\n");
	return (1);
}