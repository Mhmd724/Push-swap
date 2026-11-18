/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:06:30 by mharajli          #+#    #+#             */
/*   Updated: 2024/09/03 15:10:42 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = get_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if (biggest_node == (*a)->next)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
