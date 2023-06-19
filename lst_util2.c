/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:58:17 by vchulkai          #+#    #+#             */
/*   Updated: 2023/05/01 23:05:32 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/// @brief  find the list have the item less than ran or not
/// @param lst
/// @param ran
/// @return 1 mean have 0 means don't have
int	have_listbetween(t_list **lst, int min, int max)
{
	t_list	*t;

	t = *lst;
	while (t)
	{
		if (t->rank <= max && t->rank >= min)
			return (1);
		t = t->next;
	}
	return (0);
}

/// @brief findnearly iten that have value between min and max
/// @param lst list
/// @param min min value
/// @param max max value
/// @return return the most nearly position
int	find_nearlistbetw(t_list **lst, int min, int max, int hi)
{
	t_list	*t;
	int		i;
	int		j;
	int		sign;

	t = *lst;
	sign = 0;
	i = 0;
	j = 0;
	while (t)
	{
		if (hi == 0 || t->rank < hi - 2)
		{
			if (sign == 0 && t->rank <= max && t->rank >= min)
			{
				i = find_list_start1(lst, t->rank);
				sign++;
			}
			else if (sign != 0 && t->rank <= max && t->rank >= min)
				j = find_list_start1(lst, t->rank);
		}
		t = t->next;
	}
	sign = count_list_start1(lst);
	return (cont_finlstbetw(i, j, sign));
}

int	cont_finlstbetw(int i, int j, int sign)
{
	if (i != 0 && j != 0)
	{
		if (sign - j < i)
			return (j);
		else if (sign - j >= i)
			return (i);
	}
	else if (j == 0 && i != 0)
		return (i);
	return (i);
}

/// @brief count where the item is.
/// @param lst = list of item
/// @param ran = rank of item(start at 1 too)
/// @return 0 = there are not have the item in list other mean the
///position start at 1
int	find_list_start1(t_list **lst, int ran)
{
	t_list	*t;
	int		i;

	t = *lst;
	i = 1;
	while (t)
	{
		if (t->rank == ran)
			return (i);
		i++;
		t = t->next;
	}
	return (0);
}

/// @brief count the number of list
/// @param lst list to count
/// @return 0 = empty list other is the number of item start at 1
int	count_list_start1(t_list **lst)
{
	t_list	*t;
	int		i;

	t = *lst;
	i = 1;
	while (t)
	{
		if (!(t->next))
			return (i);
		i++;
		t = t->next;
	}
	return (0);
}
