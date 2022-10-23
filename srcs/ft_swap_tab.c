/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:10:16 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/22 14:44:48 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int		ft_push_swap(char **argv, t_list **a, t_list **b);
void	free_tabchar(char **tab);
int		which_sort(t_list **a, t_list **b);
int		list_check(char **argv, char **tab, t_list **a);

int	ft_push_swap(char **argv, t_list **a, t_list **b)
{
	char	**tab;

	tab = NULL;
	if (list_check(argv, tab, a) == 0)
	{
		if (checker_if_list_sort(*a) == 0)
			return (0);
		else
		{
			if (which_sort(a, b) == 1)
				return (1);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}

int	list_check(char **argv, char **tab, t_list **a)
{
	int	i;

	i = 1;
	if (check_list(argv, tab) == 1)
		return (1);
	else if (do_it_chainlist(argv, tab, a, i) == 1)
		return (1);
	else if (check_doublons_int(*a) == 1)
		return (1);
	else
		return (0);
}

int	which_sort(t_list **a, t_list **b)
{
	int	j;

	j = ft_lstsize(*a);
	if (j == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
	}
	else if (j == 3)
		size_3(a);
	else if (j == 5 || j == 4)
	{
		if (size_5(a, b, j))
			return (1);
	}
	else
	{
		if (ft_big_sort(a, b, j) == 1)
			return (1);
	}
	return (0);
}

void	free_tabchar(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	int		j;

	a = NULL;
	b = NULL;
	if (argc == 1 || argc == 2)
		return (0);
	j = ft_push_swap(argv, &a, &b);
	if (j == 1)
		write(1, "Error malloc\n", 13);
	tmp = a;
	while (tmp)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	a = NULL;
	return (0);
}
