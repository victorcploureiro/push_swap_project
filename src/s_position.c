/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_position.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:43:25 by vcarrara          #+#    #+#             */
/*   Updated: 2024/04/25 16:01:30 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_positions(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*cur_b;
	int				target_pos;

	cur_b = stack_b->head;
	get_cur_pos(stack_a);
	get_cur_pos(stack_b);
	target_pos = 0;
	while (cur_b)
	{
		target_pos = get_target_pos(stack_a, cur_b->i, INT_MAX, target_pos);
		cur_b->target_pos = target_pos;
		cur_b = cur_b->next;
	}
}

void	get_cur_pos(t_stack_list *stack)
{
	t_stack_node	*current;
	int				i;

	current = stack->head;
	i = 0;
	while (current)
	{
		current->current_pos = i;
		current = current->next;
		i++;
	}
}

int	get_target_pos(t_stack_list *stack, int index_b, int target_index,
		int target_pos)
{
	t_stack_node	*current_a;

	current_a = stack->head;
	while (current_a)
	{
		if (current_a->i > index_b && current_a->i < target_index)
		{
			target_index = current_a->i;
			target_pos = current_a->current_pos;
		}
		current_a = current_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	current_a = stack->head;
	while (current_a)
	{
		if (current_a->i < target_index)
		{
			target_index = current_a->i;
			target_pos = current_a->current_pos;
		}
		current_a = current_a->next;
	}
	return (target_pos);
}

int	get_lowest_i_pos(t_stack_list *stack)
{
	t_stack_node	*current;
	int				lowest_i;
	int				lowest_pos;

	current = stack->head;
	lowest_i = INT_MAX;
	get_cur_pos(stack);
	lowest_pos = current->current_pos;
	while (current)
	{
		if (current->i < lowest_i)
		{
			lowest_i = current->i;
			lowest_pos = current->current_pos;
		}
		current = current->next;
	}
	return (lowest_pos);
}
