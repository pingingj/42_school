/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:45:18 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/09 18:50:50 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_check(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (false);
	}
	return (true);
}

static void	small_cases(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->head->data;
	second = stack->head->next->data;
	third = stack->tail->data;
	if (first < second && first < third && second > third)
	{
		rotate(stack, 'a', true);
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	if (first > second && first > third && second > third)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	if (first > second && first > third && second < third)
		rotate(stack, 'a', true);
	if (first < second && first > third && second > third)
		reverse_rotate(stack, 'a');
	if (first > second && first < third && second < third)
		swap(stack, 'a');
}

static void	sort_small(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->size == 2)
	{
		if (stack->head->data > stack->tail->data)
			swap(stack, 'a');
		return ;
	}
	small_cases(stack);
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (!sort_check(stack_a))
	{
		if (stack_a->size < 4)
			sort_small(stack_a);
		else
		{
			push(stack_a, stack_b, 'b');
			if (stack_a->size > 3)
				push(stack_a, stack_b, 'b');
		}
		if(sort_check(stack_a))
			return ;
		set_index(stack_a);
		set_index(stack_b);
		give_targets_a(stack_a, stack_b);
		give_targets_b(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		get_cost(stack_b, stack_a);
		ft_printstack(stack_a, 'a');
		ft_printstack(stack_b, 'b');
/* 		make_push_b(stack_a, stack_b); */
		ft_printstack(stack_a, 'a');
		ft_printstack(stack_b, 'b');
	}
	return ;
}
