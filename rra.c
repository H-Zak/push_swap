/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:40:33 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/18 19:15:31 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

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


		
	if (a->next == NULL)
		a = tmp;
	free(tmp); //ou del
}


int	stack_size(t_list *a)
{
	int	size;
	size = 0;
	while (a && a->next)
	{
		size++;
		a = a->next;
	}
	return (size);
}