/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:45 by mharajli          #+#    #+#             */
/*   Updated: 2024/09/03 15:17:50 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!stack || !(*stack)->next)
		return ;
	last_node = get_lastnode(*stack);
	last_node->next = *stack;
	last_node->prev->next = NULL;
	last_node->next->prev = last_node;
	last_node->prev = NULL;
	*stack = last_node;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
