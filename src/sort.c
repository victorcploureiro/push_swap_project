/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:35:32 by vcarrara          #+#    #+#             */
/*   Updated: 2024/05/29 20:15:13 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (is_sorted(stack_a) == 1)
		return ;
	else
	{
		if (stack_a->len == 2)
			sa(stack_a);
		else if (stack_a->len == 3)
			sort_three(stack_a);
		else
			sort_bigger(stack_a, stack_b);
	}
}

void	sort_three(t_stack_list *stack)
{
	if (stack->head->i > stack->head->next->i
		&& stack->head->i > stack->head->next->next->i)
		ra(stack);
	else if (stack->head->next->i > stack->head->i
		&& stack->head->next->i > stack->head->next->next->i)
		rra(stack);
	if (stack->head->i > stack->head->next->i)
		sa(stack);
}

void	sort_bigger(t_stack_list *stack_a, t_stack_list *stack_b)
{
	populate_stack_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->len)
	{
		get_positions(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (is_sorted(stack_a) == 0)
		adjust_stack(stack_a);
}

void	populate_stack_b(t_stack_list *stack_a, t_stack_list *stack_b)
{
	int	len;
	int	pushed;
	int	i;

	len = stack_a->len;
	pushed = 0;
	i = 0;
	while (stack_a->len > 3 && i < len && pushed < len / 2)
	{
		if (stack_a->head->i <= len / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (len - pushed > 3)
	{
		pb(stack_a, stack_b);
		if (!stack_b->tail)
			stack_b->tail = stack_b->head;
		pushed++;
	}
}

void	adjust_stack(t_stack_list *stack_a)
{
	int	lowest_pos;
	int	len;

	len = stack_a->len;
	lowest_pos = get_lowest_i_pos(stack_a);
	if (lowest_pos > len / 2)
	{
		while (lowest_pos < len)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}
