/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:40:03 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/01/13 00:00:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	int				index;
	int				cost;
	int				data;
}					t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}					t_stack;

//--------------Main funcs-------------------------------------//
char				**error_check(int argc, char **argv);
char				*other_strjoin(char *s1, char const *s2);
void				free_split(char **split);
long				ft_atol(const char *nptr);

//--------------Stack funcs------------------------------------//
t_node				*ft_nodenew(int data);
t_stack				*make_stack(char **strings);
void				clear_stack(t_stack *stack);
void				ft_stackadd_back(t_stack *stack, t_node *new);
void				ft_stackadd_front(t_stack *stack, t_node *new);
void				ft_printstack(t_stack *stack, char which);
void				push(t_stack *stack_a, t_stack *stack_b, char which);
void				swap(t_stack *stack, char which);
void				rotate(t_stack *stack, char which, bool print);
void				reverse_rotate(t_stack *stack, char which, bool print);
void				double_rotate(t_stack *stack_a, t_stack *stack_b);
void				double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

//--------------Sort funcs-------------------------------------//
void				sort_stacks(t_stack *stack_a, t_stack *stack_b);
bool				sort_check(t_stack *stack);
t_node				*biggest_node(t_stack *stack);
t_node				*smallest_node(t_stack *stack);
void				give_targets_a(t_stack *stack_a, t_stack *stack_b);
void				give_targets_b(t_stack *stack_a, t_stack *stack_b);
void				set_index(t_stack *stack);
void				get_cost(t_stack *stack_a, t_stack *stack_b);
void				make_push_b(t_stack *stack_a, t_stack *stack_b);
void				make_push_a(t_stack *stack_a, t_stack *stack_b);

#endif