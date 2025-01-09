/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:54:16 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/09 19:10:22 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = stack_a->head;
	temp_b = stack_b->head;
	while(temp_a)
	{
		if(temp_a->index > stack_a->size / 2)
			temp_a->cost = stack_a->size - temp_a->index;
		else
			temp_a->cost = temp_a->index;
		if(temp_a->target->index > stack_b->size / 2)
			temp_a->cost += stack_b->size - temp_a->target->index;
		else
			temp_a->cost += temp_a->target->index;
		temp_a = temp_a->next;
	}
}

t_node	*find_cheapest(t_stack *stack)
{
	t_node 	*temp;
	t_node	*best_index;
	int		best_cost;

	best_cost = INT_MAX;
	best_index = stack->head;
	temp = stack->head;
	while(temp)
	{
		if(temp->cost < best_cost)
		{
			best_cost = temp->cost;
			best_index = temp;
		}
		temp = temp->next;	
	}
	return(best_index);
}

void	make_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheap_a;
	t_node	*target_a;

	cheap_a = find_cheapest(stack_a);
	target_a = cheap_a->target;
	if(cheap_a->cost == 0)
	{
		push(stack_a, stack_b, 'b');
		return ;
	}
	while(cheap_a != stack_a->head)
	{
		if(cheap_a->index > stack_a->size / 2)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a', true);
	}
	while(cheap_a->target != stack_b->head)
	{
		if(cheap_a->target->index > stack_a->size / 2)
			reverse_rotate(stack_b, 'b');
		else
			rotate(stack_b, 'b', true);
	}
	push(stack_a, stack_b, 'b');
}
