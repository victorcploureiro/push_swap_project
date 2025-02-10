/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:15:58 by vcarrara          #+#    #+#             */
/*   Updated: 2024/06/07 18:06:10 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_list	*create_stack(int argc, char *argv[])
{
	t_stack_list	*stack;

	stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!stack)
		exit(write(2, "Error\n", 6));
	ft_memset(stack, 0, sizeof(t_stack_list));
	if (argc >= 2)
		populate_stack(stack, argv, 1);
	return (stack);
}

void	populate_stack(t_stack_list *stack, char *argv[], int start_i)
{
	int		i;
	long	value;

	i = start_i;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
		{
			clear_stack(stack);
			exit(write(2, "Error\n", 6));
		}
		add_node(stack, value);
		i++;
	}
}

void	add_node(t_stack_list *stack, int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
	{
		clear_stack(stack);
		exit(write(2, "Error\n", 6));
	}
	ft_memset(new_node, 0, sizeof(t_stack_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if (!stack->head)
		stack->head = new_node;
	if (stack->tail)
		stack->tail->next = new_node;
	stack->tail = new_node;
	stack->len++;
}

void	clear_stack(t_stack_list *stack)
{
	t_stack_node	*cur;

	if (stack)
	{
		while (stack->head)
		{
			cur = stack->head->next;
			free(stack->head);
			stack->head = cur;
		}
		free(stack);
	}
}

int	is_sorted(t_stack_list *stack)
{
	t_stack_node	*cur;

	cur = stack->head;
	while (cur && cur->next)
	{
		if (cur->i > cur->next->i)
			return (0);
		cur = cur->next;
	}
	return (1);
}
