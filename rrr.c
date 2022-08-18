/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:46:21 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/18 15:46:48 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

void	rrr(t_list *a, t_list *b)
{
	t_list *tmp;
	
	tmp = a;
	while (a->next != NULL)
		a = a->next;
	if (a->next == NULL)
		a = tmp;
	tmp = b;
	while (b->next != NULL)
		b = b->next;
	if (b->next == NULL)
		b = tmp;
	free(tmp);
}