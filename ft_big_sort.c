/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:57:51 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/21 19:23:30 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	trie(t_list *a, int j, int *tab);
void	the_finish(t_list **a, t_list **b, int *tab);
int		the_boucle(t_list **a, t_list **b, int j);

int	ft_big_sort(t_list **a, t_list **b, int j)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc (j * sizeof(int));
	if (tab == NULL)
		return (free(tab), 1);
	trie((*a), j, &tab[0]);
	put_index(a, &tab[0], j);
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

int	the_boucle(t_list **a, t_list **b, int j)
{
	int	elu;
	int	i;

	i = 0;
	elu = 0;
	while ((i < (j - 3)))
	{
		pos(a, b);
		if (target_pos(a, b) == 1)
			return (1);
		cost_a(a, b);
		cost_b(a, b);
		elu = cout_global(a, b);
		fait_le_mouv(elu, a, b);
		i++;
	}
	return (0);
}

void	the_finish(t_list **a, t_list **b, int *tab)
{
	t_list	*tmp_a;
	int		taille;
	int		comp;

	pos(a, b);
	comp = 0;
	tmp_a = (*a);
	while (tab[0] != tmp_a->content)
		tmp_a = tmp_a->next;
	taille = ft_lstsize((*a)) / 2;
	comp = tmp_a->pos;
	while (tmp_a->pos != 0)
	{
		if (comp > taille)
			rra(a);
		else
			ra(a);
		pos(a, b);
	}
}

void	trie(t_list *a, int j, int *tab)
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
