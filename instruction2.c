/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:58:27 by vchulkai          #+#    #+#             */
/*   Updated: 2023/04/03 15:58:27 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_rotate(t_list **a, char ch)
{
	t_list	*t;
	t_list	*tt;

	t = *a;
	while (t->next->next)
	{
		t = t->next;
	}
	tt = t->next;
	t->next = NULL;
	tt->next = *a;
	*a = tt;
	if (ch == 'a')
		write(1, "rra\n", 4);
	else if (ch == 'b')
		write(1, "rrb\n", 4);
}

void	re_roall(t_list **a, t_list **b)
{
	re_rotate(a, 't');
	re_rotate(b, 't');
	write(1, "rrr\n", 4);
}
