/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:16:03 by vcarrara          #+#    #+#             */
/*   Updated: 2024/05/15 16:21:56 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_list *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	second = stack->head;
	first = stack->head->next;
	second->next = first->next;
	second->prev = first;
	first->next = second;
	first->prev = NULL;
	if (second->next != NULL)
		second->next->prev = second;
	stack->head = first;
}

void	sa(t_stack_list *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_list *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_list *stack_a, t_stack_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
