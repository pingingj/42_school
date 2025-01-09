/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:25:13 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/06 18:18:10 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_nodenew(int data)
{
	t_node	*newlist;

	newlist = malloc(sizeof(t_node));
	if (newlist == NULL)
		return (NULL);
	newlist->data = data;
	newlist->cost = 0;
	newlist->cost = 0;
	newlist->prev = NULL;
	newlist->next = NULL;
	newlist->target = NULL;
	return (newlist);
}

void	ft_stackadd_back(t_stack *stack, t_node *new)
{
	stack->size++;
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	new->prev = stack->tail;
	stack->tail->next = new;
	stack->tail = new;
	new->next = NULL;
}

void	ft_stackadd_front(t_stack *stack, t_node *new)
{
	stack->size++;
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	new->next = stack->head;
	stack->head->prev = new;
	stack->head = new;
	new->prev = NULL;
}

void	ft_printstack(t_stack *stack, char which)
{
	int		i;
	t_node	*temp;

	i = 1;
	if (stack->head == NULL)
	{
		printf("%c is empty\n\n", which);
		return ;
	}
	ft_printf("Stack %c: \n", which);
	temp = stack->head;
	ft_printf("stack size: %d\n", stack->size);
	while (temp != NULL)
	{
		ft_printf("%d: ", temp->index);
		ft_printf("data = %d ", temp->data);
		if (temp->target != NULL)
			ft_printf("target data = %d COST = %d", temp->target->data, temp->cost);
		ft_printf("\n");
		i++;
		temp = temp->next;
	}
	ft_printf("stack head: %d\n", stack->head->data);
	ft_printf("stack tail: %d\n\n\n", stack->tail->data);
}

void	clear_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		temp = temp->next;
		free(stack->head);
		stack->head = temp;
	}
	free(stack);
}
