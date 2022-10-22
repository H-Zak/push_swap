/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:31:46 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/22 14:34:08 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int		target_pos(t_list **a, t_list **b);
void	target_pos_2(t_list **a, t_list **b, int *tab, int j);
void	pos(t_list **a, t_list **b);

int	target_pos(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	int		i;
	int		j;
	int		*tab;

	tmp_a = (*a);
	i = ft_lstsize((*a));
	tab = malloc (i * sizeof(int));
	if (tab == NULL)
		return (free(tab), 1);
	j = 0;
	while (tmp_a)
	{
		tab[j] = tmp_a->index;
		j++;
		tmp_a = tmp_a->next;
	}
	bubblesort(&tab[0], i);
	target_pos_2(a, b, tab, j);
	free(tab);
	return (0);
}

void	target_pos_2(t_list **a, t_list **b, int *tab, int j)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		max;

	max = j;
	tmp_b = (*b);
	tmp_a = (*a);
	while (tmp_b)
	{
		j = 0;
		while (j <= max && (tab[j] < tmp_b->index))
			j++;
		if (j >= max)
			j = 0;
		if (tmp_b->index == 1)
			j = 0;
		tmp_a = (*a);
		while (tab[j] != tmp_a->index)
			tmp_a = tmp_a->next;
		tmp_b->target_pos = tmp_a->pos;
		tmp_b = tmp_b->next;
	}
}

void	pos(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		i;

	i = 0;
	tmp_a = (*a);
	tmp_b = (*b);
	while (tmp_a)
	{
		tmp_a->pos = i;
		tmp_a = tmp_a->next;
		i++;
	}
	i = 0;
	while (tmp_b)
	{
		tmp_b->pos = i;
		tmp_b = tmp_b->next;
		i++;
	}
}
