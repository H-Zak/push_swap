/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_little_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:35:10 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/21 16:51:15 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void	bubbleSort(int *tab, int n)
{
    int i;
	int j;

	i = 0;
	while (i < (n - 1))
	{
		j = 0;
		while (j < (n - i - 1))
		{
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}