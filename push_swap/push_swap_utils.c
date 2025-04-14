/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:49:17 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/13 13:44:50 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack->head;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

t_node	*biggest_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*big;
	long	biggest;

	if (!stack->head)
		return (NULL);
	temp = stack->head;
	biggest = LONG_MIN;
	while (temp)
	{
		if (biggest < temp->data)
		{
			biggest = temp->data;
			big = temp;
		}
		temp = temp->next;
	}
	return (big);
}

t_node	*smallest_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*big;
	long	smallest;

	if (!stack->head)
		return (NULL);
	temp = stack->head;
	smallest = LONG_MAX;
	while (temp)
	{
		if (smallest > temp->data)
		{
			smallest = temp->data;
			big = temp;
		}
		temp = temp->next;
	}
	return (big);
}

void	give_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	long	value;

	temp_a = stack_a->head;
	while (temp_a)
	{
		value = LONG_MIN;
		temp_b = stack_b->head;
		while (temp_b)
		{
			if (temp_b->data < temp_a->data && value < temp_b->data)
			{
				value = temp_b->data;
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (value == LONG_MIN)
			temp_a->target = biggest_node(stack_b);
		temp_a = temp_a->next;
	}
}

void	give_targets_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	long	value;

	temp_b = stack_b->head;
	while (temp_b)
	{
		value = LONG_MAX;
		temp_a = stack_a->head;
		while (temp_a)
		{
			if (temp_a->data > temp_b->data && value > temp_a->data)
			{
				value = temp_a->data;
				temp_b->target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (value == LONG_MAX)
			temp_b->target = smallest_node(stack_a);
		temp_b = temp_b->next;
	}
}
