/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:30:57 by vchulkai          #+#    #+#             */
/*   Updated: 2023/04/03 17:17:58 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **a, char ch)
{
	int	i;
	int	j;

	if ((*a) && (*a)->next)
	{
		i = (*a)->data;
		j = (*a)->rank;
		(*a)->data = (*a)->next->data;
		(*a)->rank = (*a)->next->rank;
		(*a)->next->data = i;
		(*a)->next->rank = j;
	}
	if (ch == 'a')
		write(1, "sa\n", 3);
	else if (ch == 'b')
		write(1, "sb\n", 3);
}

void	ft_swap_all(t_list **a, t_list **b)
{
	ft_swap(a, 't');
	ft_swap(b, 't');
	write(1, "ss\n", 3);
}

void	rotate_s(t_list **a, char ch)
{
	t_list	*t;
	t_list	*tt;

	t = *a;
	(*a) = (*a)->next;
	tt = *a;
	while (tt->next)
	{
		tt = tt->next;
	}
	t->next = NULL;
	tt->next = t;
	if (ch == 'a')
		write(1, "ra\n", 3);
	else if (ch == 'b')
		write(1, "rb\n", 3);
}

void	rotate_all(t_list **a, t_list **b)
{
	rotate_s(a, 't');
	rotate_s(b, 't');
	write(1, "rr\n", 3);
}

void	push_atob(t_list **src, t_list **dst, char ch)
{
	int	i;
	int	j;

	i = (*src)->data;
	j = (*src)->rank;
	lst_addfirst(dst, i, j);
	lst_delfirst(src);
	if (ch == 'a')
		write(1, "pa\n", 3);
	else if (ch == 'b')
		write(1, "pb\n", 3);
}
