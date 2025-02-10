/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:04:02 by vcarrara          #+#    #+#             */
/*   Updated: 2024/06/07 18:19:15 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	**check_input(int argc, char **argv)
{
	int	i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			if (check_characters(argv[i]) || check_limit(argv[i]))
				exit(write(2, "Error\n", 6));
			i++;
		}
	}
	else
		exit(1);
	return (argv);
}

int	check_characters(const char *argv)
{
	if (*argv != '+' && *argv != '-' && ft_isdigit(*argv) == 0)
		return (1);
	if ((*argv == '+' || *argv == '-') && ft_isdigit(*(argv + 1)) == 0)
		return (1);
	while (*++argv)
	{
		if (ft_isdigit(*argv) == 0)
			return (1);
	}
	return (0);
}

int	check_limit(char *argv)
{
	size_t	len;

	if (!(*argv))
		return (1);
	if (*argv == '-' || *argv == '+')
		argv++;
	if (*argv == '\0')
		return (1);
	while (*argv == '0')
		argv++;
	len = 0;
	while (*argv)
	{
		if (ft_isdigit(*argv))
			argv++;
		else
			return (1);
		if (++len > 10)
			return (1);
	}
	return (0);
}

void	check_dup(t_stack_list *stack, t_stack_node *current)
{
	t_stack_node	*cur;

	cur = stack->head;
	while (cur)
	{
		if (cur != current && cur->value == current->value)
		{
			clear_stack(stack);
			exit(write(2, "Error\n", 6));
		}
		cur = cur->next;
	}
}
