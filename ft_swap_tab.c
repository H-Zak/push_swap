/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:10:16 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/09/01 14:37:29 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int ft_push_swap (char** argv, t_list *a, t_list *b);
int	check_list (char** argv, char**tab);
int	check (char** tab);
int	do_it(char** argv, char** tab, t_list *a, t_list *b);

int ft_push_swap (char** argv, t_list *a, t_list *b)
{
	int	i;
	char **tab;
//If no parameters are specified, the program must not display anything and give the prompt back.
	i = 1;
	if (check_list(argv, tab) == 1)
	{
		printf("Error\n");
		return(1);
	}
	if (check_list(argv, tab) == 2) //ajouter le while(free(tab))
	{
		do_it_chainlist(argv, tab, a, b);
		printf("good\n");
		return (2);
	}
	else
		return(0);
}

int	do_it_chainlist(char** argv, char** tab, t_list *a, t_list *b)
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
			ft_lastadd_back(&a, ft_lastnew(ft_atoi(tab[j])));
			j++;
			free(tab[j]);
		}
		j = 0;
		i++;	
	}
	//free tab
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
				return(1);
		}
		j = 0;
		i++;
	}
	// free tab
	return (2);
}

int	main (int argc, char** argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	ft_push_swap(argv, a, b);
	return (0);
}
