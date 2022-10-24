/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:15:20 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/24 18:04:28 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

static void	size_5_2(int *tab, t_list **a, t_list **b, int j);
static void	size_5_3(t_list **a, t_list **b, int j);

int	checker_if_list_sort(t_list *a)
{
	while (a->next != NULL && a->content < a->next->content)
	{
		a = a->next;
	}
	if (a->next == NULL)
		return (0);
	else
		return (1);
}

int	size_3(t_list **a)
{
	int	a_content;
	int	b;
	int	c;

	a_content = (*a)->content;
	b = (*a)->next->content;
	c = (*a)->next->next->content;
	if (a_content < b && a_content < c && b > c)
	{
		rra(a);
		sa(a);
	}
	if (a_content > b && a_content < c && b < c)
		sa(a);
	if (a_content < b && a_content > c && b > c)
		rra(a);
	if (a_content > b && a_content > c && b > c)
	{
		sa(a);
		rra(a);
	}
	if (a_content > b && a_content > c && b < c)
		ra(a);
	return (0);
}

int	size_5(t_list **a, t_list **b, int j)
{
	int		*tab;
	int		i;
	t_list	*tmp;

	tab = malloc (j * sizeof(int));
	if (tab == NULL)
		return (free(tab), 1);
	i = 0;
	tmp = (*a);
	while (i < j)
	{
		tab[i] = tmp-> content;
		tmp = tmp->next;
		i++;
	}
	bubblesort(&tab[0], j);
	size_5_2(tab, a, b, j);
	size_3(a);
	if (j == 5 && (*b)->content < (*b)->next->content)
		sb(b);
	size_5_3(a, b, j);
	free(tab);
	return (0);
}

static void	size_5_3(t_list **a, t_list **b, int j)
{
	pta(a, b);
	if (j == 5)
		pta(a, b);
	ra(a);
	if (j == 5)
		ra(a);
}

static void	size_5_2(int *tab, t_list **a, t_list **b, int j)
{
	if (j == 5)
	{
		while (j > 3)
		{
			while (1)
			{
				if (tab[4] == (*a)->content || tab[3] == (*a)->content)
					break ;
				ra(a);
			}
			j--;
			ptb(a, b);
		}
	}
	if (j == 4)
	{
		while (1)
		{
			if (tab[3] == (*a)->content)
				break ;
			ra(a);
		}
		ptb(a, b);
	}
}
