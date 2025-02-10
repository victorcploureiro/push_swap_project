/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:31:44 by vcarrara          #+#    #+#             */
/*   Updated: 2024/06/07 18:24:38 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_i(t_stack_list *stack)
{
	int				len;
	t_stack_node	*high;

	len = stack->len;
	high = NULL;
	while (len > 0)
	{
		find_highest_unassigned(stack, &high);
		if (high)
			high->i = len;
		len--;
	}
}

void	find_highest_unassigned(t_stack_list *stack, t_stack_node **high)
{
	t_stack_node	*cur;
	long			value;

	cur = stack->head;
	value = LONG_MIN;
	while (cur)
	{
		if (cur->value > value && cur->i == 0)
		{
			check_dup(stack, cur);
			value = cur->value;
			*high = cur;
			cur = stack->head;
		}
		cur = cur->next;
	}
}
