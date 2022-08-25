/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:48:25 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/25 18:40:17 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ra(t_list **a) //chacun nombre gagne une place et le premier devient le dernier
{
	t_list	*tmp;
	t_list	*second;

	tmp = (*a);
	second = (*a)->next;
	while((*a)->next == NULL)
		(*a) = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
	(*a) = second;
}

void    rb(t_list **b)
{
    t_list  *tmp;
    t_list  *second;

    tmp = (*b);
    second = (*b)->next;
    while ((*b)->next != NULL)
        (*b) = (*b)->next;
    (*b)->next = tmp;
    (*b)->next->next = NULL;
    (*b) = second;
}


void	rr (t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*second;

	tmp = (*a);
	second = (*a)->next;
	while((*a)->next == NULL)
		(*a) = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
	(*a) = second;
    
	tmp = (*b);
    second = (*b)->next;
    while ((*b)->next != NULL)
        (*b) = (*b)->next;
    (*b)->next = tmp;
    (*b)->next->next = NULL;
    (*b) = second;
}