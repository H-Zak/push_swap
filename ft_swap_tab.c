/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:10:16 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/21 16:28:33 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int		ft_push_swap (char** argv, t_list **a, t_list **b);
void	free_tabchar(char **tab);
int	which_sort(t_list **a, t_list **b, int j);

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

	tab = NULL;
	if (list_check(argv, tab, a) == 0)
	{
		if (checker_if_list_sort(*a) == 0)
			return(0);//pas besoin de return il faut qu'il aille free a la fin ou mettre une fonction qui free
		else
		{
			if (which_sort(a, b, j) == 1)
				return (1);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}

int	list_check (char **argv, char **tab, t_list **a)
{
	if (check_list(argv, tab) == 1)
		return (1);
	else if (do_it_chainlist(argv, tab, a) == 1)//free chainlist
		return (1);
	else if (check_doublons_int(*a, tab) == 1)//free la chainlist
		return (1);
	else
		return (0);
}

int	which_sort(t_list **a, t_list **b, int j)
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
	{
		if (size_5(a, b, j))
			return(1);
	}
	else
	{
		if (ft_big_sort(a ,b, j) == 1)
			return(1);
	}
	return (0);
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

// int	main (int argc, char** argv)
// {
// 	t_list	*a;
// 	t_list	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (argc == 1 || argc == 2) //If no parameters are specified, the program must not display anything and give the prompt back.
// 		return (0);
// 	if (ft_push_swap(argv, &a, &b) == 0)
// 		return (0);
// 	else
// 		return(-1);
// 	//test(a);
// 	//print_list(a);
// }
int	main (int argc, char** argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	int	j;

	a = NULL;
	b = NULL;
	if (argc == 1 || argc == 2) //If no parameters are specified, the program must not display anything and give the prompt back.
		return (0);
	j = ft_push_swap(argv, &a, &b);
	if (j == 1)
		write(1, "Error malloc\n", 13);
	//mettre le free chainlist ici ou dans la fonction push_swap
	tmp = a;
	while(tmp)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	a = NULL;
	//test(a);
	//print_list(a);
	return (0);
}