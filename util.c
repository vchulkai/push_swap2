/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:51:22 by vchulkai          #+#    #+#             */
/*   Updated: 2023/06/12 23:09:58 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *c)
{
	char	*a;
	long	i;
	long	sign;

	sign = 1;
	i = 0;
	a = c;
	if (*a == '-')
	{
		sign = -sign;
		a++;
	}
	else if (*a == '+')
		a++;
	while (*a >= '0' && *a <= '9')
	{
		i = 10 * i + (*a - '0');
		a++;
		if (i > INT_MAX || i < INT_MIN)
			break ;
	}
	return (sign * i);
}
