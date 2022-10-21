/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:40:33 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/21 18:39:26 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rra(t_list **a)
{
	t_list	*tmp;

	write (1, "rra\n", 4);
	tmp = (*a);
	while ((*a)->next->next != NULL)
		(*a) = (*a)->next;
	(*a)->next->next = tmp;
	tmp = (*a)->next;
	(*a)->next = NULL;
	(*a) = tmp;
}

void	rrb(t_list **b)
{
	t_list	*tmp;

	write (1, "rrb\n", 4);
	tmp = (*b);
	while ((*b)->next->next != NULL)
		(*b) = (*b)->next;
	(*b)->next->next = tmp;
	tmp = (*b)->next;
	(*b)->next = NULL;
	(*b) = tmp;
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*tmp;

	write (1, "rrr\n", 4);
	tmp = (*a);
	while ((*a)->next->next != NULL)
		(*a) = (*a)->next;
	(*a)->next->next = tmp;
	tmp = (*a)->next;
	(*a)->next = NULL;
	(*a) = tmp;
	tmp = (*b);
	while ((*b)->next->next != NULL)
		(*b) = (*b)->next;
	(*b)->next->next = tmp;
	tmp = (*b)->next;
	(*b)->next = NULL;
	(*b) = tmp;
}
