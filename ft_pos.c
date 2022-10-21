/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:31:46 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/21 16:50:10 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int		target_pos(t_list **a, t_list **b);
void	target_pos_2 (t_list **a, t_list **b, int *tab, int j, int max);
void	pos (t_list **a, t_list **b);


int	target_pos(t_list **a, t_list **b)
{
	t_list  *tmp_a;
	t_list  *tmp_b;
	int i;
	int j;
	int *tab;
	int max;

	tmp_b = (*b);
	tmp_a = (*a);
	i = ft_lstsize((*a));
	tab = malloc (i * sizeof(int));
	if (tab == NULL)
		return (free(tab), 1);
	j = 0;
	while (tmp_a)
	{
		tab[j] = tmp_a->index; //mettre directement dans l'ordre les index ?
		j++;
		tmp_a = tmp_a->next;
	}
	max = j;
	bubbleSort(&tab[0], i);
	target_pos_2(a, b, tab, j, max);
	free(tab);
	return (0);
}

void	target_pos_2(t_list **a, t_list **b, int *tab, int j, int max)
{
	t_list  *tmp_a;
	t_list  *tmp_b;

	tmp_b = (*b);
	tmp_a = (*a);
	while (tmp_b)
	{
		j = 0;
		while (tab[j] && (tab[j] < tmp_b->index)) //table de j existe 
			j++;
		if (j >= max)//viser la position la plus petit
			j = 0;
		if (tmp_b->index == 1)
			j = 0;
		tmp_a = (*a);
		while (tab[j] != tmp_a->index)
			tmp_a = tmp_a->next;
		tmp_b->target_pos = tmp_a->pos; //trouver a quel index il correspond et ensuite donne sa pos a b
		tmp_b = tmp_b->next;
	}
}

void	pos(t_list **a, t_list **b)
{
	t_list  *tmp_a;
	t_list  *tmp_b;
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