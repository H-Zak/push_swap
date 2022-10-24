/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:31:30 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/24 17:19:28 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	put_index(t_list **a, int *tab);
void	do_the_mov(int i, t_list **a, t_list **b);
void	mov_condition(t_list **a, t_list **b, int chosen);
void	mov_cond_2(t_list **a, t_list **b, int chosen);

void	do_the_mov(int chosen, t_list **a, t_list **b)
{
	t_list	*tmp_b;

	tmp_b = (*b);
	while (tmp_b->pos != chosen)
		tmp_b = tmp_b->next;
	if (tmp_b->cost_b == 0 && tmp_b->cost_a == 0)
		return (pta(a, b));
	while (tmp_b->cost_a != 0 || tmp_b->cost_b != 0)
	{
		mov_condition(a, b, chosen);
		mov_cond_2(a, b, chosen);
		if (tmp_b->cost_b == 0 && tmp_b->cost_a == 0)
			pta(a, b);
	}
}

void	mov_cond_2(t_list **a, t_list **b, int chosen)
{	
	t_list	*tmp_b;

	tmp_b = (*b);
	while (tmp_b->pos != chosen)
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
		rr(a, b);
		tmp_b->cost_a = tmp_b->cost_a - 1;
		tmp_b->cost_b = tmp_b->cost_b - 1;
	}
}

void	mov_condition(t_list **a, t_list **b, int chosen)
{
	t_list	*tmp_b;

	tmp_b = (*b);
	while (tmp_b->pos != chosen)
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

void	put_index(t_list **a, int *tab)
{
	int		i;
	t_list	*tmp;

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
