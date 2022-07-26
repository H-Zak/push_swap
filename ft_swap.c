/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:14:57 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/07/15 11:32:42 by zakariyaham      ###   ########.fr       */
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
    
    if (argc > 2)
    {
        i = 1;
        while(argv[i])
        {
            if ((ft_isdigit(argv[i]) = 102) || (ft_space(argv[i]== 102)))
                i++;
			else
				return(ft_printf("Error"));
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
                return(ft_printf("Error"));
        }
    }
}


int main(argc, argv)
{
    ft_lecture(argc, argv[1]);
}