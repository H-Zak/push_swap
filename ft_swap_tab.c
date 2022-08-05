/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:10:16 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/05 17:56:45 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

int ft_push_swap (char** argv);
int	check_list (char** argv, char**tab);
int	check (char** tab);
int	do_it(char** argv, char** tab, int i);

int ft_push_swap (char** argv)
{
	int	i;
	char **tab;

	i = 1;
	if (check_list(argv, tab) == 1)
	{
		printf("Error\n");
		return(1);
	}
	if (check_list(argv, tab) == 2) //ajouter le while(free(tab))
	{
		do_it(argv, tab, i);
		printf("t'es le boss\n");
		return (2);
	}
	else
		return(0);
}

int	do_it(char** argv, char** tab, int i)
{
	int	j;
	
	j = 0;
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		while (tab[j])
		{
			ft_lastadd_back(a, ft_lastnew(ft_atoi(tab[j])));
			j++;
			free(tab[j])
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
	t_list	a;
	t_list	b;

	a = NULL;
	b = NULL;
	ft_push_swap(argv);
	return (0);
}