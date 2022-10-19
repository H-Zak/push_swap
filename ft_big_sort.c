/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:57:51 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/19 18:29:08 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void    trie (t_list *a, t_list *b, int j, int *tab);

//coder les pieges (si la suite est strictement decroissante)
// faire tp, cost a et cost b
//trouver la suite la plus longue 
//pour le Tp on doit trouver ou il se plasse environ si son index est 4 et qu'en face il y a 2 et un 6 on choisis de le mettre au dessus du 6 (pk pas faire en fonction du cout )
// a la fin peut etre creer un **tab qui enregistrera tous les writes pour ensuite comparer si on peut remplacer 2 actions par une seule
//utiliser la mediane pour le cout B
// celui qui prend le moins de cout pour se tp 
//ne pas oublier le cout du pta mais c'est le cas pour tous donc pas besoin de le prendre en compte

int ft_big_sort(t_list **a, t_list **b, int j)//possibilite d'envoyer tab et de faire une seule fois le trie pour tous les cas de trie 3,5 et plus
{
    int *tab;
    int i;
    int elu;
    
    elu = 0;
    i = 0;
    //tout push dans b sauf trois (peut etre des exception ou une optimisation a faire)
    tab = malloc (j * sizeof(int));
    // if (tab == NULL)
	    // 	return(NULL);
    //donne les valeurs aux tableay
    trie((*a), (*b), j, &tab[0]);
    put_index(a, &tab[0], j);
    //push dans b, choisir la bonne methode
    while(i < (j - 3))
    {
        ptb(a, b);
        i++;
    }
    size_3(a);
    i = 0;
    while((i < (j - 3)))//while((*b))
    {
        pos(a, b);
        target_pos(a, b);
        cost_a(a, b);
        cost_b(a, b);
        elu = cout_global(a, b);
        fait_le_mouv(elu, a, b);
        i++;
    }
    //une fois la boucle finis tout est trie mais peut etre pas avec le premier index en haut
    the_finish(a, b, &tab[0]);
    free(tab);
    return (0);
}


void	trie(t_list *a, t_list *b, int j, int *tab)//pourquoi j'avais redeclarer tab, pas besois de return tab si j'ai enovoyer l'adresse ?
{
//	int *tab;
	int	i;
	t_list *tmp;
	
	i = 0;
	tmp = a;
	while (i < j)
	{
		tab[i] = tmp-> content;
		tmp = tmp->next;
		i++;
	}
	bubbleSort(&tab[0], j);
  //  return (tab);
}