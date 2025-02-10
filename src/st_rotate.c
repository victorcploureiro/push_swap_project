/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:16:08 by vcarrara          #+#    #+#             */
/*   Updated: 2024/04/25 15:22:40 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_list *stack)
{
	t_stack_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	tmp->prev = stack->tail;
	tmp->next = NULL;
	stack->tail->next = tmp;
	stack->tail = tmp;
}

void	ra(t_stack_list *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_list *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_list *stack_a, t_stack_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
