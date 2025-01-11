/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:45:18 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/11 01:28:30 by root             ###   ########.fr       */
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
		reverse_rotate(stack, 'a', true);
	}
	if (first > second && first > third && second > third)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a', true);
	}
	if (first > second && first > third && second < third)
		rotate(stack, 'a', true);
	if (first < second && first > third && second > third)
		reverse_rotate(stack, 'a', true);
	if (first > second && first < third && second < third)
		swap(stack, 'a');
}

static void	sort_small(t_stack *stack)
{
	if (!stack || stack->size == 1)
		return ;
	if (stack->size == 2)
	{
		if (stack->head->data > stack->tail->data)
			swap(stack, 'a');
		return ;
	}
	small_cases(stack);
}

static	void	last_rotate(t_stack *stack_a)
{
	t_node *smallest;

	set_index(stack_a);
	smallest = smallest_node(stack_a);
	while(smallest != stack_a->head)
	{
		if(smallest->index > stack_a->size / 2)
			reverse_rotate(stack_a, 'a', true);
		else
			rotate(stack_a, 'a', true);
	}
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 4)
		sort_small(stack_a);
	else
	{
		push(stack_a, stack_b, 'b');
		if (stack_a->size > 3)
			push(stack_a, stack_b, 'b');
	}
	while (!sort_check(stack_a) && stack_a->size > 3)
	{
		stack_inits(stack_a, stack_b);
 		make_push_b(stack_a, stack_b); 
	}
	sort_small(stack_a);
	while (stack_b->size != 0)
	{
		stack_inits(stack_a, stack_b);
 		make_push_a(stack_a, stack_b); 
	}
	last_rotate(stack_a);
	return ;
}
