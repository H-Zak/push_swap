/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deplacement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:31:30 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/21 16:47:59 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	put_index(t_list **a, int *tab, int j);
void	fait_le_mouv(int i, t_list **a, t_list **b);
void	mouv_condition(t_list **a, t_list **b, int elu);
void	mouv_condition_2(t_list **a, t_list **b, int elu);//trop de fonction dans ce fichier

void	fait_le_mouv(int elu, t_list **a, t_list **b) //utiliser (*b) et non pas une temporaire pour economiser deux lignes
{
	t_list *tmp_b;

	tmp_b = (*b);
	while (tmp_b->pos != elu)
		tmp_b = tmp_b->next;
	if (tmp_b->cost_b == 0 && tmp_b->cost_a == 0)//je ne comptabilise pas le cout du pta donc quand le cout est a 0 pour les 2 cote le while ne le prend pas en compte, possible de le mettre apres le while
		return (pta(a,b));
	while (tmp_b->cost_a != 0 || tmp_b->cost_b != 0)
	{
		mouv_condition(a, b, elu);
		mouv_condition_2(a, b, elu);
		if (tmp_b->cost_b == 0 && tmp_b->cost_a == 0)
			pta(a,b);
	}
}

void	mouv_condition_2(t_list **a, t_list **b, int elu)
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

void	mouv_condition(t_list **a, t_list **b, int elu)
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

void	put_index(t_list **a, int *tab, int j)
{
	int		i;
	t_list  *tmp;

	i = 1;
	tmp = (*a);
	while (tmp)
	{
		while (tmp->content != tab[i - 1])
			i++;
		tmp->index = i;
		tmp = tmp->next;
		i = 1;
	}
}