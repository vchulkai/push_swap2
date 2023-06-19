/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:50:40 by vchulkai          #+#    #+#             */
/*   Updated: 2023/06/12 22:58:47 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assigned_rank(t_list **a)
{
	t_list	*head;
	t_list	*move;
	int		i;

	head = *a;
	while (head)
	{
		i = 1;
		move = *a;
		while (move)
		{
			if ((head)->data > (move)->data)
				i++;
			move = (move)->next;
		}
		(head)->rank = i;
		head = head->next;
	}
}

void	free_stacka(t_list **a)
{
	t_list	*t;

	while (*a)
	{
		t = (*a);
		*a = (*a)->next;
		free(t);
	}
}

int	checkvalue(long *ans)
{
	int	i;
	int	j;

	i = 0;
	if (!ans)
		return (write_err(), 0);
	while (ans[i])
	{
		j = i;
		while (ans[j])
		{
			if (i != j && ans[i] == ans[j])
				return (write_err(), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	write_err(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	checkspace(char *ch)
{
	char	c;

	c = *ch;
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v')
		return (1);
	else
		return (0);
}
