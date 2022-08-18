/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:49:02 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/08/16 12:51:54 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_sort_int_tab(int *tab, int size);

int	main()
{
	int i;
	int tab[7] = {10, 80, 30, 90, 40, 50, -70};
	ft_sort_int_tab(tab, 7);
	for (i = 0; i < 7; i++ )
        printf("%d\n", tab[i]);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (i < size)
	{
		while (j < size)
		{	
			if (tab[i] < tab[j])
				j++;
			if (tab[j] < tab[i])
			{
				a = tab[j];
				b = tab[i];
				tab[j] = b;
				tab [i] = a;
			}
		}
		i++;
		j = i + 1;
	}
}



/*a et b vont servir a swap les valeurs*/
/*while(i < size)
ici on compare la valeur du tableau a l'emplacement i avec celle de i+1 */

/*while (tab[i] < tab[j] && j < 5) 
on compare le tableau aux autres valeurs en incrementant j, 
si une valeur inferieur existe alors i et j s'echangent*/

/*j = i+1; 
j permet de comparer la valeur du l'emplacement i avec les suivante 
donc il doit juste etre devant i */
