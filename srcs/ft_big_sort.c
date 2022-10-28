/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:57:51 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/28 14:54:00 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort(t_list *a, int j, int *tab);
static void		the_finish(t_list **a, t_list **b, int *tab);
static int		the_boucle(t_list **a, t_list **b, int j);

int	ft_big_sort(t_list **a, t_list **b, int j)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc (j * sizeof(int));
	if (tab == NULL)
		return (free(tab), 1);
	sort((*a), j, &tab[0]);
	put_index(a, &tab[0]);
	while (i < (j - 3))
	{
		ptb(a, b);
		i++;
	}
	size_3(a);
	i = 0;
	if (the_boucle(a, b, j) == 1)
		return (free(tab), 1);
	the_finish(a, b, &tab[0]);
	free(tab);
	return (0);
}

static int	the_boucle(t_list **a, t_list **b, int j)
{
	int	chosen;
	int	i;

	i = 0;
	chosen = 0;
	while ((i < (j - 3)))
	{
		pos(a, b);
		if (target_pos(a, b) == 1)
			return (1);
		cost_a(a, b);
		cost_b(b);
		chosen = cost_global(b);
		do_the_mov(chosen, a, b);
		i++;
	}
	return (0);
}

static void	the_finish(t_list **a, t_list **b, int *tab)
{
	t_list	*tmp_a;
	int		size;
	int		comp;

	pos(a, b);
	comp = 0;
	tmp_a = (*a);
	while (tab[0] != tmp_a->content)
		tmp_a = tmp_a->next;
	size = ft_lstsize((*a)) / 2;
	comp = tmp_a->pos;
	while (tmp_a->pos != 0)
	{
		if (comp > size)
			rra(a);
		else
			ra(a);
		pos(a, b);
	}
}

static void	sort(t_list *a, int j, int *tab)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = a;
	while (i < j)
	{
		tab[i] = tmp-> content;
		tmp = tmp->next;
		i++;
	}
	bubblesort(&tab[0], j);
}
