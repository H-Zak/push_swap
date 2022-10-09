/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:37:37 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/09 18:50:01 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void    sa(t_list **a)
{
    t_list *tmp;
    t_list *second;

	write (1, "sa\n", 3);
    tmp = (*a);
    second = (*a)->next;
    (*a)->next = (*a)->next->next;
    (*a) = second;
    (*a)->next = tmp;
}
//que faire si il n'y a que un seul nombre dans la list :
// if (a->next == NULL)
//     printf("Error");

void    sb(t_list **b)
{
    t_list *tmp;
    t_list *second;

	write (1, "sb\n", 3);
    tmp = (*b);
    second = (*b)->next;
    (*b)->next = (*b)->next->next;
    (*b)->next->next = second;
    (*b) = second;
 //   return (second);
}

void    ss(t_list **a, t_list **b)
{
    t_list *tmp;
    t_list *second;

    write (1, "ss\n", 3);
    tmp = (*a);
    second = (*a)->next;
    (*a)->next = (*a)->next->next;
    (*a)->next->next = second;
    (*a) = second;
    
    tmp = (*b);
    second = (*b)->next;
    (*b)->next = (*b)->next->next;
    (*b)->next->next = second;
    (*b) = second;
}