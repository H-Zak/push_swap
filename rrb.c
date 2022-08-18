/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:47:00 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/18 17:57:59 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

void	rrb(t_list *b)// recevoir * ou **
{
	t_list *tmp;
	
	tmp = b;
	while (b->next != NULL)
		b = b->next;
	if (b->next == NULL)
		b = tmp;
	free(tmp); //ou del
}