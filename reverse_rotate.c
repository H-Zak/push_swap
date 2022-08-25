/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:40:33 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/25 18:44:16 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rra (t_list **a)
{
	t_list *tmp;

	tmp = (*a);
	while ((*a)->next->next != NULL)
		(*a) = (*a)->next;
	(*a)->next->next = tmp;
	tmp = (*a)->next;
	(*a)->next = NULL;
	(*a) = tmp;	
		
}


// chaque nombre perd une place et le dernier devient le premier 
void	rrb(t_list **b)// recevoir ** (pour avoir l'adresse du pointeur et donc modifier veritablement sa valeur)
{
	t_list *tmp;
	
	tmp = (*b);
	while((*b)->next->next !=NULL)
		(*b) = (*b)->next;
	(*b)->next->next = tmp;
	tmp = (*b)->next;
	(*b)->next = NULL;
	(*b) = tmp;
	
}

	// if (a->next == NULL)
	// 	a = tmp;
	// free(tmp); //ou del
	
void	rrr(t_list **a, t_list **b)
{
	t_list *tmp;
	
	tmp = (*a);
	while ((*a)->next->next != NULL)
		(*a) = (*a)->next;
	(*a)->next->next = tmp;
	tmp = (*a)->next;
	(*a)->next = NULL;
	(*a) = tmp;	

	tmp = (*b);
	while((*b)->next->next !=NULL)
		(*b) = (*b)->next;
	(*b)->next->next = tmp;
	tmp = (*b)->next;
	(*b)->next = NULL;
	(*b) = tmp;
}

