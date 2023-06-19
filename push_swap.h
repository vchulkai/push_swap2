/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:45:36 by vchulkai          #+#    #+#             */
/*   Updated: 2023/06/12 23:03:10 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				rank;
	struct s_list	*next;
}					t_list;

void	ft_swap(t_list **a, char ch);
void	ft_swap_all(t_list **a, t_list **b);
void	rotate_s(t_list **a, char ch);
void	rotate_all(t_list **a, t_list **b);
void	push_atob(t_list **src, t_list **dst, char ch);
void	re_rotate(t_list **a, char ch);
void	re_roall(t_list **a, t_list **b);
void	c_sort3(t_list **a);
void	control_sort(t_list **a, t_list **b, int n);
void	c_sort(t_list **a, t_list **b, int n);
int		checker_sort(t_list **a);
void	*lst_create(t_list **a, int dat, int j);
void	lst_addback(t_list **lst, int i, int j);
void	lst_addfirst(t_list **lst, int i, int j);
void	lst_delfirst(t_list **lst);
void	lst_dellast(t_list **lst);
int		l_fi(t_list	**lst, int rank);
void	assigned_rank(t_list **a);
long	ft_atoi(char *c);
int		checker_dsort(t_list **a);
int		dist_between(int first, int second, int max);
int		l_count(t_list **lst);
int		l_count_digit(t_list **lst, int digit, int num);
int		l_fid(t_list **lst, int digit, int num);
void	c_sortmore10(t_list **a, t_list **b, int n);
int		l_fmax(t_list **lst);
void	c_sorta(t_list **a, t_list **b, int i, char *ch);
int		find_n(int num);
void	c_sortb(t_list **a, t_list **b, int i);
int		*list_push(t_list **a, int i, int valueb);
int		count_pos(t_list **a, int i, int valueb);
void	s_sortb(t_list **a, t_list **b, int *x, int i);
int		l_ffirst(t_list **lst, int digit, int valued);
int		l_flast(t_list **lst, int digit, int valued);
void	c_sortb2(t_list **a, t_list **b, int i);
int		l_fblast(t_list	**lst, int digit, int valued);
int		*list_push2(t_list **a, int digit);
void	s_sorta(t_list **a, t_list **b, int digit, char *ch);
int		find_nearlistbetw(t_list **lst, int min, int max, int hi);
int		have_listbetween(t_list **lst, int min, int max);
int		find_list_start1(t_list **lst, int ran);
int		count_list_start1(t_list **lst);
int		f_inter(t_list **lst);
int		general_sorttb(t_list **a, t_list **b, int inter, char *ch);
void	general_sortta(t_list **a, t_list **b, int max, char *ch);
void	c_sort3m(t_list **a, t_list **b);
int		general_sorttafter2(t_list **a, t_list **b, int inter, char *ch);
void	sortfirst2chuck(t_list **a, t_list **b, int inter, char *ch);
int		general_sorttafirst(t_list **a, t_list **b, int inter, char *ch);
void	c_sort5(t_list **a, t_list **b, int hi);
int		cont_finlstbetw(int i, int j, int sign);
void	c_sortless10(t_list **a, t_list **b, int no_item);
long	*input_argv(char **argv, int argc, int i);
int		countallchar(char *ar);
void	sort_node(t_list **a, t_list **b, int j);
void	free_stacka(t_list **a);
int		checkvalue(long *ans);
int		write_err(void);
int		checkspace(char *ch);
int		check_char(char **argv, int argc);

#endif
