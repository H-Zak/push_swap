/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:28:01 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/21 16:28:17 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int		check_list (char** argv, char**tab);
int		check (char** tab);
int		do_it_chainlist(char** argv, char** tab, t_list **a);// mettre un return en cas d'erreur
int		check_doublons_int(t_list *a, char **tab);
int		list_check (char **argv, char **tab, t_list **a);
void boucle(t_list *a, int *tabtest, int i); //une fonction en trop dans ce fichier

//je recois un tab et que j'utilise puis free et re utilise apres, il est utiliser pour plusieurs split

int	check_list (char** argv, char** tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		tab = ft_split(argv[j], ' ');
		if (tab[0] == NULL || tab == NULL)
			return (1);
		if (check(tab) == 1)
			return (1);
		j++;
	}
	return (0);
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
			else if (tab[i][j] == '+' && (47 < tab[i][j + 1] && tab[i][j + 1] < 58))
				j++;
			else if (47 < tab[i][j] && tab[i][j] < 58)
				j++;
			else
				return(free_tabchar(tab),1);
		}
		j = 0;
		i++;
	}
	return (free_tabchar(tab),2);
}

int do_it_chainlist(char** argv, char** tab, t_list **a)
{
	int	j;
	int	i;

	i = 1;
	j = 0;
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		if (tab[0] == NULL || tab == NULL)
			return (1);
		while (tab[j])
		{
			if(ft_atol(tab[j]) != ft_atoi(tab[j]))
				return(1);
			ft_lastadd_back(a, ft_lstnew(ft_atol(tab[j])));
			if (a == NULL)
				return (1);
			free(tab[j]);
			j++;
		}
		j = 0;
		i++;	
	}
	return (0);
}

int	check_doublons_int(t_list *a, char **tab)
{
	int	i;
	int	j;
	int *tabtest;

	i = ft_lstsize(a);
	tabtest = malloc (i * sizeof(int));
	if (tabtest == NULL)
		return(free(tabtest), 1); //gerer cette erreur 
	i = 0;
	boucle(a, &tabtest[0], i);
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
	return (free(tabtest),0);
}

void boucle(t_list *a, int *tabtest, int i)
{
	while(a)
	{
		tabtest[i] = a->content;
		a = a->next;
		i++;
	}
	
}