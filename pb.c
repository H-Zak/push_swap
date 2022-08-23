/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:14:40 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/19 12:46:24 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

void	ptb (t_list **a, t_list **b)
{
	t_list *tmp;
	
	if (b == NULL)
	{
		b = ft_lastnew(a->content);
		tmp = a;
		a = a->next;
		del(tmp); //ou free tmp
		//delete le premier de a ou reculer tout de 1
	}
	else
	{
		ft_lstadd_front(&b, a);
		tmp = a;
		a = a->next;
		del(tmp); //ou free tmp
	}	 
}