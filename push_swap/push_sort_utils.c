/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:54:16 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/13 13:43:36 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;

	temp_a = stack_a->head;
	while (temp_a)
	{
		if (temp_a->index > stack_a->size / 2)
			temp_a->cost = stack_a->size - temp_a->index;
		else
			temp_a->cost = temp_a->index;
		if (temp_a->target->index > stack_b->size / 2)
			temp_a->cost += stack_b->size - temp_a->target->index;
		else
			temp_a->cost += temp_a->target->index;
		temp_a = temp_a->next;
	}
	temp_a = stack_a->head;
	while (temp_a)
	{
		if ((temp_a->index > stack_a->size / 2
				&& temp_a->target->index > stack_b->size / 2)
			|| (temp_a->index <= stack_a->size / 2
				&& temp_a->target->index <= stack_b->size / 2))
			temp_a->cost -= 1;
		temp_a = temp_a->next;
	}
}

static t_node	*find_cheapest(t_stack *stack)
{
	t_node	*temp;
	t_node	*best_index;
	int		best_cost;

	best_cost = INT_MAX;
	best_index = stack->head;
	temp = stack->head;
	while (temp)
	{
		if (temp->cost < best_cost)
		{
			best_cost = temp->cost;
			best_index = temp;
		}
		temp = temp->next;
	}
	return (best_index);
}

static bool	check_double_rotate(t_stack *stack_a, t_stack *stack_b,
		t_node *small)
{
	if (small != stack_a->head && small->target != stack_b->head)
	{
		if (small->index > stack_a->size / 2
			&& small->target->index > stack_b->size / 2)
		{
			double_reverse_rotate(stack_a, stack_b);
			return (true);
		}
		if (small->index < stack_a->size / 2
			&& small->target->index < stack_b->size / 2)
		{
			double_rotate(stack_a, stack_b);
			return (true);
		}
	}
	return (false);
}

void	make_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheap_a;

	cheap_a = find_cheapest(stack_a);
	while (cheap_a != stack_a->head || cheap_a->target != stack_b->head)
	{
		if (!check_double_rotate(stack_a, stack_b, cheap_a))
		{
			if (cheap_a != stack_a->head)
			{
				if (cheap_a->index > stack_a->size / 2)
					reverse_rotate(stack_a, 'a', true);
				else
					rotate(stack_a, 'a', true);
			}
			if (cheap_a->target != stack_b->head)
			{
				if (cheap_a->target->index > stack_b->size / 2)
					reverse_rotate(stack_b, 'b', true);
				else
					rotate(stack_b, 'b', true);
			}
		}
	}
	push(stack_a, stack_b, 'b');
}

void	make_push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheap_b;

	cheap_b = find_cheapest(stack_b);
	while (cheap_b != stack_b->head || cheap_b->target != stack_a->head)
	{
		if (!check_double_rotate(stack_b, stack_a, cheap_b))
		{
			if (cheap_b != stack_b->head)
			{
				if (cheap_b->index > stack_b->size / 2)
					reverse_rotate(stack_b, 'b', true);
				else
					rotate(stack_b, 'b', true);
			}
			if (cheap_b->target != stack_a->head)
			{
				if (cheap_b->target->index > stack_a->size / 2)
					reverse_rotate(stack_a, 'a', true);
				else
					rotate(stack_a, 'a', true);
			}
		}
	}
	push(stack_b, stack_a, 'a');
}
