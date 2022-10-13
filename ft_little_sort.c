/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:15:20 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/13 18:20:11 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void swap(int* xp, int* yp);
void bubbleSort(int *tab, int n);
void	size_5_2(int *tab, t_list **a, t_list **b, int i, int j);

int	checker_if_list_sort (t_list *a)
{
	while(a->next != NULL && a->content < a->next->content)
	{
		a = a->next;
	}
	if (a->next == NULL)
	{
		printf("c'est deja trie");
		return(0);
	}
	else
	{
		printf("c'est pas trie");
		return (1);
	}
}

int size_3 (t_list **a)
{
	if ((*a)->content < (*a)->next->content && (*a)->content < (*a)->next->next->content && (*a)->next->content > (*a)->next->next->content)
	{
		rra(a);
		sa(a);
	}
	if ((*a)->content > (*a)->next->content && (*a)->content < (*a)->next->next->content && (*a)->next->content < (*a)->next->next->content)
		sa(a);
	if ((*a)->content < (*a)->next->content && (*a)->content > (*a)->next->next->content && (*a)->next->content > (*a)->next->next->content)
		rra(a);
	if ((*a)->content > (*a)->next->content && (*a)->content > (*a)->next->next->content && (*a)->next->content > (*a)->next->next->content)
	{
		sa(a);
		rra(a);
	}
	if ((*a)->content > (*a)->next->content && (*a)->content > (*a)->next->next->content && (*a)->next->content < (*a)->next->next->content)
		ra(a);
	return (0);	
}

void	size_5 (t_list **a, t_list **b, int j)
{
	int *tab;
	int	i;
	t_list *tmp;
	
	tab = malloc (j * sizeof(int));
	// if (tab == NULL)
	// 	return(NULL);
	i = 0;
	tmp = (*a);
	while (i < j)
	{
		tab[i] = tmp-> content;
		tmp = tmp->next;
		i++;
	}
	bubbleSort(&tab[0], j);
	size_5_2(tab, a, b, i, j);
	size_3(a);
	if (j == 5 && (*b)->content < (*b)->next->content)
		sb(b);
	pta(a, b);
	if (j == 5)
		pta(a, b);
	ra(a);
	if (j == 5)
		ra(a);
	//free(tab);
}

void	size_5_2(int *tab, t_list **a, t_list **b, int i, int j)
{
	if (j == 5)
	{
		while (i > 3)
		{
			while (1)
			{
				if (tab[4] == (*a)->content || tab[3] == (*a)->content)
					break;
				ra(a);
			}
			i--;
			ptb(a, b);
		}
	}
	if (j == 4)
	{
		while (1)
		{
			if (tab[3] == (*a)->content)
				break;
			ra(a);
		}
		ptb(a, b);
	}
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int *tab, int n)
{
    int i;
	int j;

	i = 0;
	while(i < (n - 1))
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
//     for (i = 0; i < n - 1; i++)
 
//         // Last i elements are already in place
//         for (j = 0; j < n - i - 1; j++)
//             if (arr[j] > arr[j + 1])
//                 swap(&arr[j], &arr[j + 1]);