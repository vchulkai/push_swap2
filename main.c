/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:02:47 by vchulkai          #+#    #+#             */
/*   Updated: 2023/06/18 15:50:19 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		j;
	long	*input;

	b = NULL;
	i = 0;
	j = 0;
	if (!check_char(argv, argc))
		return (write_err(), 0);
	while (i < argc -1)
		j += countallchar(argv[++i]);
	i = 0;
	input = input_argv(argv, argc, j);
	if (!checkvalue(input) || j == 1)
		return (free(input), 0);
	lst_create(&a, input[i++], -999);
	while (i < j)
		lst_addback(&a, input[i++], -999);
	free(input);
	assigned_rank(&a);
	sort_node(&a, &b, j);
	free_stacka(&a);
	return (0);
}

int	check_char(char **argv, int argc)
{
	int		i;
	char	*c;

	i = 1;
	while (i < argc)
	{
		c = argv[i++];
		if (!c[0] || ((c[0] < '0' || c[0] > '9') && !c[1]))
			return (0);
		while (*c)
		{
			if ((*c == '+' || *c == '-')
				&& (*(c + 1) >= '0' && *(c + 1) <= '9'))
				c++;
			while (*c && *c >= '0' && *c <= '9')
				c++;
			if (*c && *c != ' ' && *c != '\n'
				&& *c != '\t' && *c != '\v' && *c != '\f')
				return (0);
			else if (*c)
				c++;
		}
	}
	return (1);
}

/*int	checkerror(char **argv, int argc)
{
	int		i;
	char	*c;

	i = 1;
	while (i < argc)
	{
		c = argv[i++];
		while (*c)
		{
			if (*c > '9' && *c < '0' && *c != ' ' && *c != '\n' && *c != '\t'
				&& *c != '\v' && *c != '\f')
				return (0);
			else
				c++;
		}
		i++;
	}
}*/

void	sort_node(t_list **a, t_list **b, int j)
{
	assigned_rank(a);
	if (checker_sort(a))
		return ;
	if (j > 5)
		general_sortta(a, b, general_sorttb(a, b, f_inter(a), "ab"), "ab");
	else if (j > 3)
		c_sortless10(a, b, j);
	else
		c_sort3(a);
}

long	*input_argv(char **argv, int argc, int j)
{
	int		i;
	long	*ans;
	char	*t;

	i = 0;
	ans = (long *)malloc(sizeof(long) * j);
	j = 0;
	while (i < argc - 1)
	{
		t = argv[++i];
		while (*t)
		{
			while (*t && checkspace(t))
				t++;
			if (*t)
				ans[j++] = ft_atoi(t);
			if (ans[j - 1] > INT_MAX || ans[j - 1] < INT_MIN)
				return (free(ans), NULL);
			if (*t == '-' || *t == '+')
				t++;
			while (*t && ((*t >= '0' && *t <= '9')))
				t++;
		}
	}
	return (ans);
}

int	countallchar(char *ar)
{
	int		i;
	char	*c;

	i = 0;
	c = ar;
	while (*c)
	{
		while (*c && (*c == ' ' || *c == '\n' || *c == '\t'
				|| *c == '\v' || *c == '-' || *c == '+'))
			c++;
		if (*c >= '0' && *c <= '9')
			i++;
		while (*c && (*c >= '0' && *c <= '9'))
			c++;
	}
	return (i);
}
