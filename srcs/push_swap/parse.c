/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:30:08 by mharajli          #+#    #+#             */
/*   Updated: 2024/09/03 15:33:30 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool isint(char *str)
{
	bool is_int;
	unsigned int neg_sign;
	unsigned int i;

	i = 0;
	neg_sign = 0;
	is_int = true;
	while (str[i] && is_int)
	{
		if (str[i] == '-' && neg_sign < 1)
			neg_sign++;
		else if (!ft_isdigit(str[i]))
			is_int = false;
		i++;
	}
	return (!is_int);
}

bool atoi_check(const char *str, int *n)
{
	int sign;
	bool overflow;

	*n = 0;
	sign = -1;
	overflow = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = 1;
	while (ft_isdigit(*str))
	{
		*n = (*n * 10) - (*str - '0');
		if (*n > 0 || (*n <= INT_MIN && sign < 0))
			overflow = true;
		str++;
	}
	printf("nb before: %d\n", *n);
	*n *= sign;
	printf("nb after: %d\n", *n);
	return (overflow);
}

bool there_duplicates(t_stack *a, long n)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->nbr == n)
			return (true);
		a = a->next;
	}
	return (false);
}
