/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:10:16 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/20 16:32:02 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int		ft_push_swap (char** argv, t_list **a, t_list **b);
void	free_tabchar(char **tab);
void	which_sort(t_list **a, t_list **b, int j);

void	print_list(t_list *a)
{
	while (a)
	{
		printf("%ld\n", a->content);
		a = a->next;
	}
}
// amelioration : utiliser un check_list en moins, ne pas faire split a chaque fois (donc utiliser ***tab ?), free apres split (faire une fonction free ?)
int ft_push_swap (char** argv, t_list **a, t_list **b)
{
	int	j;
	char **tab;
	t_list	*tmp;

	tab = NULL;
	if (list_check(argv, tab, a) == 0)
	{
		if (checker_if_list_sort(*a) == 0)
			return(0);//pas besoin de return il faut qu'il aille free a la fin ou mettre une fonction qui free
		else
			which_sort(a, b, j);
	}
	else
		printf("Error\n");
	//free chainlist
	/*
	tmp = (*a);
	while(tmp)
	{
		tmp = (*a)->next;
		free(a);
		a = tmp;
	}
	*/
	// while(a)
	// {
	// 	ft_lstdelone(a, free);
	// 	(*a) = (*a)->next;
	// }
	return (0);
}

void	which_sort(t_list **a, t_list **b, int j)
{
	j = ft_lstsize(*a);
			if (j == 2)
			{
				if((*a)->content > (*a)->next->content)
					sa(a);
			}
			else if (j == 3)
				size_3(a);
			else if (j == 5 || j == 4)
				size_5(a, b, j);
			else
				ft_big_sort(a ,b, j);
}

void	free_tabchar(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main (int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || argc == 2) //If no parameters are specified, the program must not display anything and give the prompt back.
		return (0);
	ft_push_swap(argv, &a, &b);
	//test(a);
	//print_list(a);
	return (0);
}
