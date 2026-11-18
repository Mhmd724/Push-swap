/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:11:15 by mharajli          #+#    #+#             */
/*   Updated: 2024/09/03 15:12:33 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*temp;

	if (!*stack_from)
		return ;
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	temp->prev = NULL;
	if (!*stack_to)
	{
		*stack_to = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack_to;
		temp->next->prev = temp;
		*stack_to = temp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}
