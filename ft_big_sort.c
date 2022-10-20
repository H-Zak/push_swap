/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:57:51 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/20 15:32:40 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void    trie (t_list *a, t_list *b, int j, int *tab);
void    the_finish (t_list **a, t_list **b, int *tab);

//coder les pieges (si la suite est strictement decroissante)
//trouver la suite la plus longue 
// a la fin peut etre creer un **tab qui enregistrera tous les writes pour ensuite comparer si on peut remplacer 2 actions par une seule
//ne pas oublier le cout du pta mais c'est le cas pour tous donc pas besoin de le prendre en compte

int ft_big_sort(t_list **a, t_list **b, int j)//possibilite d'envoyer tab et de faire une seule fois le trie pour tous les cas de trie 3,5 et plus
{
    int *tab;
    int i;
    int elu;
    
    elu = 0;
    i = 0;
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

void    the_finish (t_list **a, t_list **b, int *tab)
{
    t_list *tmp_a;
    t_list *tmp_b;
    int i;
    int taille;
    int comp;

    pos(a,b);
    i = 0;
    comp = 0;
    tmp_a = (*a);
    tmp_b = (*b);
    while (tab[0] != tmp_a->content)
        tmp_a = tmp_a->next;
    taille = ft_lstsize((*a)) / 2;
    comp = tmp_a->pos; 
    while(tmp_a->pos != 0)
    {
        if (comp > taille)
            rra(a);
        else
            ra(a);
        pos(a,b);
    }
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