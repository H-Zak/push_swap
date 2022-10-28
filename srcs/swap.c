/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:37:37 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/28 14:54:51 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **a)
{
	t_list	*tmp;
	t_list	*second;

	write (1, "sa\n", 3);
	tmp = (*a);
	second = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a) = second;
	(*a)->next = tmp;
}

void	sb(t_list **b)
{
	t_list	*tmp;
	t_list	*second;

	write (1, "sb\n", 3);
	tmp = (*b);
	second = (*b)->next;
	(*b)->next = (*b)->next->next;
	(*b) = second;
	(*b)->next = tmp;
}

void	ss(t_list **a, t_list **b)
{
	t_list	*second;

	write (1, "ss\n", 3);
	second = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a)->next->next = second;
	(*a) = second;
	second = (*b)->next;
	(*b)->next = (*b)->next->next;
	(*b)->next->next = second;
	(*b) = second;
}
