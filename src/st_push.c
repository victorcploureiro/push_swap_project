/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:16:11 by vcarrara          #+#    #+#             */
/*   Updated: 2024/04/25 15:29:41 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_list *src_stack, t_stack_list *dest_stack)
{
	t_stack_node	*src_second;

	if (src_stack->head == NULL)
		return ;
	src_second = src_stack->head->next;
	if (src_second)
		src_second->prev = NULL;
	else
		src_stack->tail = NULL;
	src_stack->head->next = dest_stack->head;
	if (dest_stack->head)
		dest_stack->head->prev = src_stack->head;
	dest_stack->head = src_stack->head;
	if (!dest_stack->tail)
		dest_stack->tail = dest_stack->head;
	src_stack->head = src_second;
	src_stack->len--;
	dest_stack->len++;
}

void	pa(t_stack_list *stack_b, t_stack_list *stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_list *stack_a, t_stack_list *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
