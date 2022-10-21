/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:37 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/21 16:51:53 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	pta(t_list **a, t_list **b) // le premier de b devient le premier de a
{
	t_list *tmp;

	write (1, "pa\n", 3);
	// if (a == NULL)
	// {
	// 	a = ft_lastnew((*b)->content);
	// 	tmp = b;
	// 	b = (*b)->next;
	// 	del(tmp); //ou free tmp
	// 	//delete le premier de a ou reculer tout de 1
	// }
	// else
	// {
		tmp = (*b)->next;
		(*b)->next = (*a);
		(*a) = (*b);
		(*b) = tmp;		
		//del(tmp); //ou free tmp
	// }
}

void	ptb(t_list **a, t_list **b) // le premier de a devient le premier de b
{
	t_list *tmp;

	write (1, "pb\n", 3);
	// if (b == NULL)
	// {
	// 	b = ft_lastnew((*a)->content);
	// 	tmp = a;
	// 	(*a) = (*a)->next;
	// 	del(tmp); //ou free tmp
	// 	//delete le premier de a ou reculer tout de 1
	// }
	// else
	// {
		//ft_lstadd_front(&b, a);
		tmp = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = tmp;
		//del(tmp); //ou free tmp
	// }	 
}