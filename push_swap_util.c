/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:46:18 by vchulkai          #+#    #+#             */
/*   Updated: 2023/05/02 01:48:32 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_sort3(t_list **a)
{
	while (!checker_sort(a))
	{
		if ((*a)->next->next)
		{
			if (((*a)->rank > (*a)->next->next->rank)
				&& ((*a)->rank > (*a)->next->rank))
				rotate_s(a, 'a');
			else if ((*a)->next->rank > (*a)->rank
				&& (*a)->next->rank > (*a)->next->next->rank)
				re_rotate(a, 'a');
			else
				ft_swap(a, 'a');
		}
		else
			ft_swap(a, 'a');
	}
}

int	checker_sort(t_list **a)
{
	t_list	*t;
	int		i;

	t = *a;
	i = t->rank;
	while (t)
	{
		if (i > t->rank)
			return (0);
		i = t->rank;
		t = t->next;
	}
	return (1);
}

void	c_sortless10(t_list **a, t_list **b, int no_item)
{
	while (have_listbetween(a, no_item - 4, no_item - 3))
	{
		if ((*a)->rank <= no_item - 3 && (*a)->rank >= no_item - 4)
			push_atob(a, b, 'b');
		else if (find_nearlistbetw(a, no_item - 4, no_item - 3, 0)
			<= (no_item - 1) / 2)
			rotate_s(a, 'a');
		else
			re_rotate(a, 'a');
	}
	c_sort3(a);
	while (*b)
	{
		push_atob(b, a, 'a');
	}
	if ((*a)->rank > (*a)->next->rank)
		ft_swap(a, 'a');
}
