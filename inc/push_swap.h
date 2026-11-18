/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:50:14 by mharajli          #+#    #+#             */
/*   Updated: 2024/09/03 15:04:34 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// algorithms
void		stack_sort(t_stack **a, t_stack **b);
void		sort_three(t_stack **a);

// split
char		**split(char *s, char c);

// stack_utils
int			stack_len(t_stack *stack);
t_stack		*get_lastnode(t_stack *stack);
bool		stack_sorted(t_stack *stack);
t_stack		*get_min(t_stack *stack);
t_stack		*get_max(t_stack *stack);

// parse
bool		isint(char *str);
bool		atoi_check(const char *str, int *n);
bool		there_duplicates(t_stack *a, long n);

// stack_init
void		init_stack_a(t_stack **a, char **av);
void		prep_for_push(t_stack **stack,
				t_stack *top_node,
				char stack_name);

// stack_node_init
t_stack		*get_cheapest(t_stack *stack);
void		reset_cheapest(t_stack *stack);

// Nodes initiation
void		current_position(t_stack *stack);
void		set_cheapest(t_stack *stack);
void		init_nodes_a(t_stack *a, t_stack *b);
void		init_nodes_b(t_stack *a, t_stack *b);

// final_step
void		min_on_top(t_stack **a);

// operations
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

// free
void		free_array(char **arr);
void		free_stack(t_stack **stack);

#endif
