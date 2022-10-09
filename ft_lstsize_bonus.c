/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:15:20 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/09 19:33:41 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void swap(int* xp, int* yp);
void bubbleSort(int *tab, int n);

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int size_3 (t_list **a)
{
	if (ft_lstsize (*a) == 3)
	{
		if ((*a)->content < (*a)->next->content && (*a)->next->content < (*a)->next->next->content)
			return(0);
		if ((*a)->content < (*a)->next->content && (*a)->content < (*a)->next->next->content && (*a)->next->content > (*a)->next->next->content)
		{
			rra(a);
			sa(a);
			return (0);
		}
		if ((*a)->content > (*a)->next->content && (*a)->content < (*a)->next->next->content && (*a)->next->content < (*a)->next->next->content)
		{
			sa(a);
			return (0);
		}
		if ((*a)->content < (*a)->next->content && (*a)->content > (*a)->next->next->content && (*a)->next->content > (*a)->next->next->content)
		{
			rra(a);
			return (0);
		}
		if ((*a)->content > (*a)->next->content && (*a)->content > (*a)->next->next->content && (*a)->next->content > (*a)->next->next->content)
		{
			sa(a);
			rra(a);
			return (0);
		}
		if ((*a)->content > (*a)->next->content && (*a)->content > (*a)->next->next->content && (*a)->next->content < (*a)->next->next->content)
		{
			ra(a);
			return (0);
		}
		return (1);
	}
	return (0);	
}
/*
int size_5 (t_list **a, t_list **b)
{
	int	i;
	int	j;
	t_list *tmp;

	i = 0;
	j = 2;
	while (a)
	{
		tmp = (*a);
		while ((*a)->next != NULL)
		{
			if (tmp->content < (*a)->next->content)
				i++;
			(*a) = (*a)->next;
		}
		if(i >= j)
			ptb(a, b);
		if (j > 0 )
			j--;
		i = 0;
		(*a) = (*a)->next;
	}
}*/

void	size_5 (t_list **a, t_list **b)
{
	int tab[5];
	int	i;
	t_list *tmp;
	
	i = 0;
	tmp = (*a);
	while (i < 5)
	{
		tab[i] = tmp-> content;
		tmp = tmp->next;
		i++;
	}
	bubbleSort(&tab[0], 5);
	// i = 0;
	// while (i < 5)
	// {
	// 	printf("%d\n", tab[i]);
	// 	i++;
	// }
	while (i >= 0)
	{
		while (tab[3] != (*a)->content || tab[4] != (*a)->content)
		{
			ra(a);
		}
		if (tab[3] == (*a)->content || tab[4] == (*a)->content)
			ptb(a, b);
		i--;
	}
	size_3(a);
	if ((*b)->content < (*b)->next->content)
		sb(b);
	pta(a, b);
	pta(a, b);
	ra(a);
	ra(a);	
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
			if (tab[j] > tab[j+1])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
//     for (i = 0; i < n - 1; i++)
 
//         // Last i elements are already in place
//         for (j = 0; j < n - i - 1; j++)
//             if (arr[j] > arr[j + 1])
//                 swap(&arr[j], &arr[j + 1]);
}