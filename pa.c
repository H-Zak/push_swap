/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:37 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/19 12:59:19 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

void	pta (t_list **a, t_list **b)
{
	t_list *tmp;
	
	if (a == NULL)
	{
		a = ft_lastnew((*b)->content);
		tmp = b;
		b = (*b)->next;
		del(tmp); //ou free tmp
		//delete le premier de a ou reculer tout de 1
	}
	else
	{
		tmp = (*b);
		
		(*b)->next = (*a);
		
		
		ft_lstadd_front(&a, b);
		tmp = a;
		(*a) = (*a)->next;
		del(tmp); //ou free tmp
	}
}