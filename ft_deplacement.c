/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deplacement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:31:30 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/21 15:23:41 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	pos (t_list **a, t_list **b);
void	put_index(t_list **a, int *tab, int j);
int		target_pos(t_list **a, t_list **b);
void	fait_le_mouv(int i, t_list **a, t_list **b);
void	target_pos_2 (t_list **a, t_list **b, int *tab, int j, int max);
void	mouv_condition(t_list **a, t_list **b, int elu);
void	mouv_condition_2(t_list **a, t_list **b, int elu);

void	fait_le_mouv(int elu, t_list **a, t_list **b) //utiliser (*b) et non pas une temporaire pour economiser deux lignes
{
	t_list *tmp_b;

	tmp_b = (*b);
	while (tmp_b->pos != elu)
		tmp_b = tmp_b->next;
	if (tmp_b->cost_b == 0 && tmp_b->cost_a == 0)//je ne comptabilise pas le cout du pta donc quand le cout est a 0 pour les 2 cote le while ne le prend pas en compte, possible de le mettre apres le while
		return(pta(a,b));
	while (tmp_b->cost_a != 0 || tmp_b->cost_b != 0)
	{
		mouv_condition(a, b, elu);
		mouv_condition_2(a, b, elu);
		if (tmp_b->cost_b == 0 && tmp_b->cost_a == 0)
			pta(a,b);
	}
}

void mouv_condition_2(t_list **a, t_list **b, int elu)
{	
	t_list *tmp_b;

	tmp_b = (*b);
	while (tmp_b->pos != elu)
		tmp_b = tmp_b->next;
	if (tmp_b->cost_a > 0 && tmp_b->cost_b <= 0)
	{
		ra(a);
		tmp_b->cost_a = tmp_b->cost_a - 1;   
	}
	if (tmp_b->cost_b > 0 && tmp_b->cost_a <= 0)
	{
		rb(b);
		tmp_b->cost_b = tmp_b->cost_b - 1;
	}
	if (tmp_b->cost_a > 0 && tmp_b->cost_b > 0)
	{
		rr(a , b);
		tmp_b->cost_a = tmp_b->cost_a - 1;
		tmp_b->cost_b = tmp_b->cost_b - 1;
	}
	
}

void mouv_condition(t_list **a, t_list **b, int elu)
{
	t_list *tmp_b;

	tmp_b = (*b);
	while (tmp_b->pos != elu)
		tmp_b = tmp_b->next;
	if (tmp_b->cost_a < 0 && tmp_b->cost_b < 0)
	{
		rrr(a, b);
		tmp_b->cost_a = tmp_b->cost_a + 1;
		tmp_b->cost_b = tmp_b->cost_b + 1;
	}
	if (tmp_b->cost_a < 0 && tmp_b->cost_b >= 0)
	{
		rra(a);
		tmp_b->cost_a = tmp_b->cost_a + 1;
	}
	if (tmp_b->cost_b < 0 && tmp_b->cost_a >= 0)
	{
		rrb(b);
		tmp_b->cost_b = tmp_b->cost_b + 1;
	}
}

int    target_pos (t_list **a, t_list **b)
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
	//mettre le while dans une autre fonction
	target_pos_2(a, b, tab, j, max);
	
	//free(tab);
	return (0);
}

void	target_pos_2 (t_list **a, t_list **b, int *tab, int j, int max)
{
	t_list  *tmp_a;
	t_list  *tmp_b;

	tmp_b = (*b);
	tmp_a = (*a);
	
	while (tmp_b)
	{
		j = 0;
		while(tab[j] && (tab[j] < tmp_b->index)) //table de j existe 
			j++;
		if (j == max)//viser la position la plus petit
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
	int i;
	
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

void	put_index(t_list **a, int *tab, int j)
{
	int i;
	t_list  *tmp;

	i = 1;
	tmp = (*a);
	while(tmp)
	{
		while(tmp->content != tab[i - 1])
			i++;
		tmp->index = i;
		tmp = tmp->next;
		i = 1;
	}
}