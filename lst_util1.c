/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virun <virun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:48:20 by vchulkai          #+#    #+#             */
/*   Updated: 2023/05/13 17:33:04 by virun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*lst_create(t_list **a, int dat, int j )
{
	(*a) = (t_list *)malloc(sizeof(t_list));
	(*a)->data = dat;
	(*a)->rank = j;
	(*a)->next = NULL;
	return (a);
}

void	lst_addback(t_list	**lst, int i, int j)
{
	t_list	*t_lst;

	t_lst = *lst;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = (t_list *)malloc(sizeof(t_list));
	(*lst)->next->data = i;
	(*lst)->next->rank = j;
	(*lst)->next->next = NULL;
	(*lst) = t_lst;
	return ;
}

void	lst_addfirst(t_list	**lst, int i, int j)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof(t_list));
	t->data = i;
	t->rank = j;
	t->next = (*lst);
	(*lst) = t;
}

void	lst_delfirst(t_list **lst)
{
	t_list	*t;

	t = *lst;
	*lst = (*lst)->next;
	t->next = NULL;
	free(t);
}

void	lst_dellast(t_list **lst)
{
	t_list	*t;

	t = *lst;
	while (*lst)
	{
		if ((*lst)->next == NULL)
		{
			free((*lst));
			(*lst) = NULL;
			break ;
		}
		(*lst) = (*lst)->next;
	}
	*lst = t;
}

/*int		l_fi(t_list	**lst, int	ra)
{
	int	i;
	t_list	*t;
	int	j;

	i = 0;
	j = -1;
	t = *lst;
	while (t)
	{
		i++;
		if (t->rank == ra)
			return(i);
		t = t->next;
	}
	// if (!(t->next))
	// 	return (-1);
	return (j);
}

int		l_count(t_list	**lst)
{
	int	i;
	t_list	*t;

	i = 0;
	t = *lst;
	while (t)
	{
		if (t->next)
		{
			i++;
			t = t->next;
		}
		else
			return(i);
	}
	return (i);
}

int		l_fid(t_list **lst, int digit, int num)
{
	int	first;
	int	last;
	int	end;
	t_list	*t;

	first = 0;
	t = *lst;
	end = 0;
	last = 0;
	while (t)
	{
		if (last != 0 && ((t->rank) / digit) % 10 == num)
			last++;
		else if (((t->rank) / digit) % 10 == num)
		{
			first++;
			last++;
		}
		end++;
		t = t->next;
	}
	if (first > (end - last) || first == 0)
		return (last);
	return (first);
}

int		l_count_digit(t_list **lst, int digit, int num)
{
	int	i;
	t_list	*t;

	i = 0;
	t = *lst;
	while (t)
	{
		if (((t->rank) / digit) % 10 == num)
			i++;
		t = t->next;
	}
	// printf("\nOMG:%d",i);
	return (i);
}

int		l_fmax(t_list	**lst)
{
	t_list	*t;
	int		i;

	t = *lst;
	i = -1;
	while (t)
	{
		if (t->rank > i)
			i = t->rank;
		t = t->next;
	}
	return (i);
}

int		l_ffirst(t_list	**lst, int	digit, int valued)
{
	t_list	*t;
	int	devided;
	int		i;

	t = *lst;
	i = 0;
	devided = 1;
	while (digit-- > 1)
		devided *= 10;
	while (t)
	{
		if (((t->rank) / devided) % 10 == valued)
			return (i);
		t = t->next;
		i++;
	}
	return (-1);
}

int		l_flast(t_list	**lst, int	digit, int valued)
{
	t_list	*t;
	int	devided;
	int		i;
	int		k;

	t = *lst;
	i = 0;
	devided = 1;
	k = -1;
	while (digit-- > 1)
		devided *= 10;
	while (t)
	{
		if (((t->rank) / devided) % 10 == valued)
		{
			// printf("\n\n%d\n", t->rank);
			k = t->rank;
		}
		t = t->next;
		i++;
	}
	return (k);
}

int		l_fblast(t_list	**lst, int	digit, int valued)
{
	t_list	*t;
	int	devided;
	int		i;
	int		k;
	int		j;

	t = *lst;
	devided = 1;
	k = -1;
	i = 1;
	j = -1;
	while (digit-- > 1)
		devided *= 10;
	while (t)
	{
		if (((t->rank) / devided) % 10 == valued && i != 1)
			k = j;
		if (((t->rank) / devided) % 10 == valued)
		{
			j = t->rank;
			i = 0;
		}
		t = t->next;

	}
	// if (k == -1 && j != -1)
	// 	k = j;
	return (k);
}

*/
