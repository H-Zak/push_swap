/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:21:49 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/03 16:08:00 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_isdigit(char** argv, int i, int j);
int	check_list(char **argv);
int ft_push_swap (char** argv);
int ft_space(int c);

int ft_push_swap (char** argv)
{
	int	i;

	if (check_list(argv) == 1)
		return(printf("Error\n"));

}

int	check_list(char **argv)
{
	int	j;
	int	i;
	
	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] == '\0') // ou "\0"
			return (1);
		if (argv[i][j + 1] == '\0' && ft_isdigit(argv, i, j) == 1)
			return (1);
		if (ft_isdigit(argv, i, j) == 1) // 
			return (1);
		if (ft_isdigit(argv, i, j) == 102) // 
			i++;
	}
	
	return (printf("t'es le boss"));
}

int	ft_isdigit(char** argv, int i, int j)
{

	while (argv[i][j])
	{
		if (ft_space(argv[i][j]) == 102)
		{
			while (ft_space(argv[i][j]) == 102)
				j++;
		}
		else if (argv[i][j] == 45 && (47 < argv[i][j + 1] && argv[i][j + 1] < 58))
			j++;
		else if (47 < argv[i][j] && argv[i][j] < 58)
		{
			while(47 < argv[i][j] && argv[i][j] < 58)
				j++;
		}
		else
			break;
	}
	if ((47 > argv[i][j] && argv[i][j] > 58) && ft_space(argv[i][j]) != 102)
		return (1);
	else
		return (102);
}

int ft_space(int c)
{
	if (c == 32)// rajouter les autres espaces et le "\n"
		return (102);
	else
		return(0);
}

int	main (int argc, char** argv)
{
	ft_push_swap(argv);
	return (0);
}