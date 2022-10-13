/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:57:51 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/13 18:37:03 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	*trie (t_list *a, t_list *b, int j, int *tab);
pos(t_list **a, t_list **b);


// faire tp, cost a et cost b

int ft_big_sort(t_list **a, t_list **b, int j, int *tab)
{
    int *tab;
    
    tab = malloc (j * sizeof(int));
    // if (tab == NULL)
	    // 	return(NULL);
    //donne les valeurs aux tableay
    trie_index(a, b, j, &tab[0]);
    put_index_pos(a, &tab[0], j);
    pos(a, b);
    //free(tab)
}

int pos(t_list **a, t_list **b)
{
    t_list  *tmp_a;
    t_list  *tmp_b;
    int i;
    
    i = 0;
    tmp_a = (*a);
    tmp_b = (*b);
    while (tmp_a)
    {
        tmp_a->pos = i;
        tmp_a = tmp_a->next;
        i++;
    }
    i = 0;
    while (tmp_b)
    {
        tmp_b->pos = i;
        tmp_b = tmp_b->next;
        i++;
    }    
}

void put_index(t_list **a, int *tab, int j)
{
    int i;
    t_list  *tmp;

    i = 1;
    tmp = (*a);
    while(tmp)
    {
        while(tmp->content != tab[i - 1])
            i++;
        tmp->index = i;
        tmp = tmp->next;
        a = 1;
    }
}

int	*trie(t_list *a, t_list *b, int j, int *tab)
{
	int *tab;
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
    return (tab);
}