/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:37 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/18 16:33:58 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

void	pa (t_list **a, t_list **b)
{
	t_list *tmp;
	
	if (a == NULL)
	{
		a = ft_lastnew(b->content);
		tmp = b;
		b = b->next;
		del(tmp); //ou free tmp
		//delete le premier de a ou reculer tout de 1
	}
	else
	{
		ft_lstadd_front(&a, b);
		tmp = a;
		a = a->next;
		del(tmp); //ou free tmp
	}
}