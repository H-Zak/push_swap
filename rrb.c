/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:47:00 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/19 12:30:55 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

void	rrb(t_list **b)// recevoir * ou **
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
	// tmp = b;
	// while (b->next != NULL)
	// 	b = b->next;
	// if (b->next == NULL)
	// 	b = tmp;
	// free(tmp); //ou del