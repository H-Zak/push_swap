/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:21:49 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/07/29 15:19:56 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_push_swap (int argc, char** argv)
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
		if (ft_space(j) == 102)
			j++;
		if (ft_isdigit(argv, i, j) == 102)
			i++;
		if (ft_space(j) != 102)
			return (printf("Error\n"));
	}
	
}

int	ft_isdigit(char** argv, int i, int j)
{
	if (j == 45)
		j++;
	while (argv[i][j])
	{
		if (47 < j && j < 58) // rajouter le - et accepter un seul moins et voir forcement un noombre/chiffre apres un moins
			j++;
		else
			return (102);
	}
}

int ft_space(int c)
{
	if (c == 32)// rajouter les autres espaces et le "\n"
		return (102);
	else
		return(0);
}