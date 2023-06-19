/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:21:15 by vchulkai          #+#    #+#             */
/*   Updated: 2023/05/02 01:48:00 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	general_sorttb(t_list **a, t_list **b, int inter, char *ch)
{
	int	i;
	int	j;
	int	hi;

	i = 1;
	hi = count_list_start1(a);
	j = inter;
	if (hi > 10)
		sortfirst2chuck(a, b, j, ch);
	while (*a && count_list_start1(a) > 3)
	{
		while (count_list_start1(a) > 3 && have_listbetween(a, i, j))
		{
			if ((*a)->rank <= j && (*a)->rank >= i && (*a)->rank < hi - 2)
				push_atob(a, b, ch[1]);
			else if (find_nearlistbetw(a, i, j, hi) <= count_list_start1(a) / 2)
				rotate_s(a, ch[0]);
			else
				re_rotate(a, ch[0]);
		}
		i += inter;
		j += inter;
	}
	c_sort3m(a, b);
	return (j);
}

void	sortfirst2chuck(t_list **a, t_list **b, int inter, char *ch)
{
	int	i;
	int	j;
	int	hi;
	int	mid;

	i = 1;
	j = 2 * inter;
	hi = count_list_start1(a);
	while (count_list_start1(a) > 3 && have_listbetween(a, i, j))
	{
		mid = count_list_start1(a) / 2;
		if ((*a)->rank <= j && (*a)->rank >= i && (*a)->rank < hi - 2)
		{
			if ((*b) && (*b)->next && (*b)->rank <= inter)
				rotate_s(b, ch[1]);
			push_atob(a, b, ch[1]);
		}
		else if ((*b) && (*b)->next && (*b)->rank <= inter
			&& find_nearlistbetw(a, i, j, hi) <= mid)
			rotate_all(a, b);
		else if (find_nearlistbetw(a, i, j, hi) <= mid)
			rotate_s(a, ch[0]);
		else
			re_rotate(a, ch[0]);
	}
}

void	general_sortta(t_list **a, t_list **b, int max, char *ch)
{
	int	mid;
	int	min;

	min = max - 2;
	while (*b)
	{
		min = max - 2;
		while (have_listbetween(b, min, max))
		{
			mid = count_list_start1(b) / 2;
			if ((*b)->rank <= max && (*b)->rank >= min)
				push_atob(b, a, ch[0]);
			else if (find_nearlistbetw(b, min, max, 0) <= mid)
				rotate_s(b, ch[1]);
			else
				re_rotate(b, ch[1]);
			c_sort3m(a, b);
		}
		max -= 3;
	}
}

void	c_sort3m(t_list **a, t_list **b)
{
	if ((*a)->next->rank < (*a)->rank)
		ft_swap(a, 'a');
	if ((*a)->next->rank > (*a)->next->next->rank)
	{
		if ((*b) && (*b)->next && (*b)->rank < (*b)->next->rank)
			rotate_all(a, b);
		else
			rotate_s(a, 'a');
		if ((*b) && (*b)->next && (*b)->rank < (*b)->next->rank)
			ft_swap_all(a, b);
		else
			ft_swap(a, 'a');
		re_rotate(a, 'a');
	}
	if ((*b) && (*b)->next
		&& (*a)->next->rank < (*a)->rank && (*b)->rank < (*b)->next->rank)
		ft_swap_all(a, b);
	else if ((*a)->next->rank < (*a)->rank)
		ft_swap(a, 'a');
}

int	f_inter(t_list **lst)
{
	int	inter;

	if (count_list_start1(lst) < 10)
		inter = 3;
	else if (count_list_start1(lst) <= 100)
		inter = 21;
	else if (count_list_start1(lst) <= 300)
		inter = 32;
	else
		inter = 48;
	return (inter);
}
