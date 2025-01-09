/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:38:44 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/09 18:50:56 by dgarcez-         ###   ########.fr       */
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
		if (sort_check(stack_a))
			ft_printf("sorted lil bro\n");
		else
			ft_printf("stupid\n");
		ft_printstack(stack_a, 'a');
		ft_printstack(stack_b, 'b');
		ft_printf("SMALLEST NODE LIL BRO %d", find_cheapest(stack_b));
		clear_stack(stack_a);
		clear_stack(stack_b);
		free_split(strings);
		return (0);
	}
	return (1);
}