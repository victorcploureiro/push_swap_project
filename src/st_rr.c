/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:16:06 by vcarrara          #+#    #+#             */
/*   Updated: 2024/04/25 15:16:49 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_list *stack)
{
	t_stack_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->next = stack->head;
	tmp->prev = NULL;
	stack->head->prev = tmp;
	stack->head = tmp;
}

void	rra(t_stack_list *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_list *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_list *stack_a, t_stack_list *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
