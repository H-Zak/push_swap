/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:37 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/23 19:07:38 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	pta(t_list **a, t_list **b)
{
	t_list	*tmp;

	write (1, "pa\n", 3);
	tmp = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void	ptb(t_list **a, t_list **b)
{
	t_list	*tmp;

	write (1, "pb\n", 3);
	tmp = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = tmp;
}
