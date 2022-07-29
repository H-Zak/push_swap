/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:14:57 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/07/27 14:42:42 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/libftprintf.h"

int	ft_isdigit(int c)
{
	if (47 < c && c < 58) // rajouter le - et accepter un seul moins et voir forcement un noombre/chiffre apres un moins
		return (102);
	else
		return (0);
}

int ft_space(int c)
{
	if (c == 32)// rajouter les autres espaces et le "\n"
		return (102);
	else
		return(0);
}

int ft_lecture(argc, argv)
{
    int i;
	int	j;
    
	j= 0;
    if (argc > 2)
    {
        i = 1;
        while(argv[i])
        {
			j = 0;
			while(argv[i][j])
			{
            	if ((ft_isdigit(argv[i][j]) = 102))
                	j++;
				else if (argv[i] == 45 && ft_isdigit(argv[i + 1]) = 102)
				
				else
					return(ft_printf("Error \n"));
			}
		}

    }
    if (argc = 2)
    {
        i = 0;
        while(argv[1][i])
        {
            if ((ft_isdigit(argv[1][i]) = 102) || (ft_space(argv[1][i]== 102)))
                i++;
            else 
                return(ft_printf("Error\n"));
        }
    }
}


int main(int argc, char** argv)
{
    if (ft_lecture(argc, argv[1]) == 0)
}

ARG="1 2 3"
./aout $ARG
./aout 1 2 3

argv[i][j]