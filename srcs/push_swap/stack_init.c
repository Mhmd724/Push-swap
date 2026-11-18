/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:43:53 by mharajli          #+#    #+#             */
/*   Updated: 2024/09/03 15:48:40 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void prep_for_push(t_stack **stack,
				   t_stack *cheapest_on_top,
				   char stack_name)
{
	while (*stack != cheapest_on_top)
	{
		if (stack_name == 'a')
		{
			if (cheapest_on_top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_on_top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void append_node(t_stack **stack, int n)
{
	t_stack *newnode;
	t_stack *last_node;

	if (!stack)
		return;
	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return;
	newnode->nbr = n;
	newnode->next = NULL;
	if (!(*stack))
	{
		newnode->prev = NULL;
		*stack = newnode;
	}
	else
	{
		last_node = get_lastnode(*stack);
		last_node->next = newnode;
		newnode->prev = last_node;
	}
}

void init_stack_a(t_stack **a, char **av)
{
	int n;
	int i;
	int status;

	i = 0;
	status = 0;
	while (av[i] && !status)
	{
		if (isint(av[i]))
			status = 1;
		if (atoi_check(av[i], &n))
			status = 2;
		if (there_duplicates(*a, n))
			status = 3;
		else
			append_node(a, (int)n);
		i++;
	}
	if (status)
	{
		free_stack(a);
		ft_putendl_fd("Error\n", 2);
	}
}
