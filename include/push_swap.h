/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:14:29 by vcarrara          #+#    #+#             */
/*   Updated: 2024/06/07 18:25:26 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					target_pos;
	int					i;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}					t_stack_node;

typedef struct s_stack_list
{
	t_stack_node		*head;
	t_stack_node		*tail;
	int					len;
}					t_stack_list;

void					free_args(int argc, char *argv[]);
char					**check_input(int argc, char *argv[]);
char					**check_two_args(int argc, char *argv[]);
int						check_characters(const char *argv);
int						check_limit(char *argv);
void					check_dup(t_stack_list *stack,
							t_stack_node *current);

t_stack_list			*create_stack(int argc, char **argv);
void					populate_stack(t_stack_list *stack, char **argv,
							int start_i);
void					add_node(t_stack_list *stack, int value);
void					clear_stack(t_stack_list *stack);
int						stack_len(t_stack_list *stack);
void					copy_stack(t_stack_list *src, t_stack_list *dest);

void					get_positions(t_stack_list *stack_a,
							t_stack_list *stack_b);
void					get_cur_pos(t_stack_list *stack);
int						get_target_pos(t_stack_list *stack, int i_b,
							int max_i, int target);
int						get_lowest_i_pos(t_stack_list *stack);
void					assign_i(t_stack_list *stack);
void					find_highest_unassigned(t_stack_list *stack,
							t_stack_node **highest);

void					get_cost(t_stack_list *stack_a, t_stack_list *stack_b);
int						get_cheaper_cost(int cost_a, int cost_b);
void					cost_is_positive(t_stack_list *stack_a,
							t_stack_list *stack_b,
							int *cheapest_a, int *cheapest_b);
void					cost_is_negative(t_stack_list *stack_a,
							t_stack_list *stack_b,
							int *cheapest_a, int *cheapest_b);
void					cost_a_is_positive(t_stack_list *stack_a,
							t_stack_list *stack_b,
							int *cheapest_a, int *cheapest_b);
void					cost_b_is_positive(t_stack_list *stack_a,
							t_stack_list *stack_b,
							int *cheapest_a, int *cheapest_b);

void					sort_stack(t_stack_list *stack_a,
							t_stack_list *stack_b);
int						is_sorted(t_stack_list *stack);
void					sort_three(t_stack_list *stack);
void					sort_bigger(t_stack_list *stack_a,
							t_stack_list *stack_b);
void					populate_stack_b(t_stack_list *stack_a,
							t_stack_list *stack_b);
void					adjust_stack(t_stack_list *stack_a);
void					do_cheapest_move(t_stack_list *stack_a,
							t_stack_list *stack_b);
void					do_move(t_stack_list *stack_a, t_stack_list *stack_b,
							int cheapest_cost_a, int cheapest_cost_b);

void					push(t_stack_list *src, t_stack_list *dest);
void					pb(t_stack_list *stack_a, t_stack_list *stack_b);
void					pa(t_stack_list *stack_a, t_stack_list *stack_b);
void					reverse_rotate(t_stack_list *stack);
void					rra(t_stack_list *stack_a);
void					rrb(t_stack_list *stack_b);
void					rrr(t_stack_list *stack_a, t_stack_list *stack_b);
void					rotate(t_stack_list *stack);
void					ra(t_stack_list *stack_a);
void					rb(t_stack_list *stack_b);
void					rr(t_stack_list *stack_a, t_stack_list *stack_b);
void					swap(t_stack_list *stack);
void					sa(t_stack_list *stack_a);
void					sb(t_stack_list *stack_b);
void					ss(t_stack_list *stack_a, t_stack_list *stack_b);

#endif