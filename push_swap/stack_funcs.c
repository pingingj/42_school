/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:33:09 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/13 13:45:08 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_1, t_stack *stack_2, char which)
{
	t_node	*temp;

	if (!stack_1->head)
		return ;
	ft_printf("p%c\n", which);
	temp = stack_1->head;
	stack_1->head = temp->next;
	ft_stackadd_front(stack_2, temp);
	stack_1->size--;
}

void	swap(t_stack *stack, char which)
{
	int	temp;

	if (stack->size <= 1)
		return ;
	ft_printf("s%c\n", which);
	temp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = temp;
}

void	rotate(t_stack *stack, char which, bool print)
{
	if (stack->size <= 1)
		return ;
	if (print)
		ft_printf("r%c\n", which);
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
}

void	reverse_rotate(t_stack *stack, char which, bool print)
{
	if (stack->size <= 1)
		return ;
	if (print)
		ft_printf("rr%c\n", which);
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
}
