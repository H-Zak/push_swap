/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:10:16 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/11 19:29:40 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int ft_push_swap (char** argv, t_list **a, t_list **b);
int	check_list (char** argv, char**tab);
int	check (char** tab);
int	do_it(char** argv, char** tab, t_list *a, t_list *b);
int do_it_chainlist(char** argv, char** tab, t_list **a);// mettre un return en cas d'erreur
int check_doublons_int(t_list *a, char **tab);
void	free_tabchar(char **tab);

void	print_list(t_list *a)
{
	while (a)
	{
		printf("%lld\n", a->content);
		a = a->next;
	}
}
// amelioration : utiliser un check_list en moins, ne pas faire split a chaque fois (donc utiliser ***tab ?), free apres split (faire une fonction free ?)
int ft_push_swap (char** argv, t_list **a, t_list **b)
{
	//int	i;
	char **tab;
//If no parameters are specified, the program must not display anything and give the prompt back.
	tab = NULL;
	//i = 1;
	if (check_list(argv, tab) != 1 && do_it_chainlist(argv, tab, a) != 1 && check_doublons_int(*a, tab) != 1)
	{
		//faire un atoi pour verifier si plus petit ou plus grand que int et verifier les doublons
	//	do_it_chainlist(argv, tab, a); // il faut envoyer a ou &a
		if (ft_lstsize(*a) == 3)
			size_3(a);
		else if (ft_lstsize(*a) == 5)
			size_5(a,b);
		return (0);
	}
	else
	{
		printf("Error\n");
		return(1);
	}
}

int	check_doublons_int(t_list *a, char **tab) //ca ne modifie pas le pointeur car j'ai envoye *a et pas **a ???
{
	int	i;
	int	j;
	int *tabtest;

	i = ft_lstsize(a);
	tabtest = malloc (i * sizeof(int));
	i = 0;
	while(a)
	{
		tabtest[i] = a->content;
		a = a->next;
		i++;
	}
	i = 0;
	while (tabtest[i])
	{
		j = i + 1;
		while (tabtest[j])
		{
			if (tabtest[i] == tabtest[j])
				return(free(tabtest), 1);
			j++;
		}
		i = i + 1;
	}
	free(tabtest);
	return (0);
}

int do_it_chainlist(char** argv, char** tab, t_list **a) //est ce que je dois envoyer **a pour que ca fonctionne ????
{
	int	j;
	int	i;

	i = 1;
	j = 0;
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		while (tab[j])
		{
			if(ft_atol(tab[j]) != ft_atoi(tab[j]))
				return(1);
			ft_lastadd_back(a, ft_lstnew(ft_atol(tab[j])));
			j++;
			free(tab[j]);
		}
		j = 0;
		i++;	
	}
	return (0);
}


int	check_list (char** argv, char** tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		tab = ft_split(argv[j], ' ');
		if (check(tab) == 1)
			return (1);
		j++;
	}
	return (2);
}

int	check (char** tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == 45 && (47 < tab[i][j + 1] && tab[i][j + 1] < 58))
				j++;
			else if (47 < tab[i][j] && tab[i][j] < 58)
				j++;
			else //free tab
			{
				free_tabchar(tab);
				return(1);
			}
		}
		j = 0;
		i++;
	}
	free_tabchar(tab);
	return (2);
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

int	main (int argc, char** argv) //commencer par faire la size et la fonction size renverra vers la fonction de trie efficace donc : 3, 5 ou plus
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	ft_push_swap(argv, &a, &b);
	print_list(a);
	return (0);
}