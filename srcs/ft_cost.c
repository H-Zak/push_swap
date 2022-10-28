/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:28:58 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/28 14:54:07 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	cost_b(t_list **b);
int		cost_global(t_list **b);
void	cost_a(t_list **a, t_list **b);
int		cost_reel(int cost_a, int cost_b);

void	cost_a(t_list **a, t_list **b)
{
	int		size;
	int		median;
	t_list	*tmp_b;

	size = ft_lstsize((*a));
	median = size / 2;
	tmp_b = (*b);
	while (tmp_b)
	{
		if (tmp_b->target_pos > median)
			tmp_b->cost_a = tmp_b->target_pos - size;
		else
			tmp_b->cost_a = tmp_b->target_pos;
		tmp_b = tmp_b->next;
	}
}

int	cost_reel(int cost_a, int cost_b)
{
	int	cost;

	cost = 0;
	if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
			return (cost_a * -1);
		else
			return (cost_b * -1);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else
	{
		if (cost_a <= 0)
			cost = (cost_a * -1) + cost_b;
		else if (cost_b <= 0)
			cost = cost_a + (cost_b * -1);
		return (cost);
	}
}

int	cost_global(t_list **b)
{
	t_list	*tmp_b;
	int		cost_1;
	int		cost_2;
	int		chosen;

	tmp_b = (*b);
	chosen = 0;
	cost_1 = cost_reel(tmp_b->cost_a, tmp_b->cost_b);
	tmp_b = tmp_b->next;
	while (tmp_b)
	{
		cost_2 = cost_reel(tmp_b->cost_a, tmp_b->cost_b);
		if (cost_1 < 0)
			cost_1 = cost_1 * -1;
		if (cost_2 < 0)
			cost_2 = cost_2 * -1;
		if (cost_2 < cost_1)
		{
			cost_1 = cost_2;
			chosen = tmp_b->pos;
		}
		tmp_b = tmp_b->next;
	}
	return (chosen);
}

void	cost_b(t_list **b)
{
	int		size;
	int		median;
	t_list	*tmp_b;

	size = ft_lstsize((*b));
	median = size / 2;
	tmp_b = (*b);
	while (tmp_b)
	{
		if (tmp_b->pos > median)
			tmp_b->cost_b = tmp_b->pos - size;
		else
			tmp_b->cost_b = tmp_b->pos;
		tmp_b = tmp_b->next;
	}
}
