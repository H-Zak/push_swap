/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:44:03 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/08/25 18:44:32 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	stack_size(t_list *a) //je pourrais possiblement en avoir besoin
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