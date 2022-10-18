/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:57:51 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/18 14:34:22 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void     cost_a(t_list **a, t_list **b);
void    trie (t_list *a, t_list *b, int j, int *tab);
void    pos (t_list **a, t_list **b);
void    put_index(t_list **a, int *tab, int j);
void     target_pos(t_list **a, t_list **b);
void     cost_b(t_list **a, t_list **b);
int    cout_global (t_list **a, t_list **b);
void    fait_le_mouv(int i, t_list **a, t_list **b);

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
    //une fois quon sait le quelle bouger, faire le mouvement, recalculer les positions et les targets
    free(tab);
    return (0);
}

void    fait_le_mouv(int elu, t_list **a, t_list **b) //utiliser (*b) et non pas une temporaire pour economiser deux lignes
{
    t_list *tmp_b;

    tmp_b = (*b);
    while (tmp_b->pos != elu)
        tmp_b = tmp_b->next;
    if (tmp_b->cost_b == 0 && tmp_b->cost_a == 0)//je ne comptabilise pas le cout du pta donc quand le cout est a 0 pour les 2 cote le while ne le prend pas en compte
        return(pta(a,b));
    while (tmp_b->cost_a != 0 || tmp_b->cost_b != 0)
    {
        if (tmp_b->cost_a < 0 && tmp_b->cost_b < 0)
        {
            rrr(a, b);
            tmp_b->cost_a = tmp_b->cost_a + 1;
            tmp_b->cost_b = tmp_b->cost_b + 1;
            
        }
        if (tmp_b->cost_a < 0 && tmp_b->cost_b == 0)
        {
            rra(a);
            tmp_b->cost_a = tmp_b->cost_a + 1;
        }
        if (tmp_b->cost_b < 0 && tmp_b->cost_a == 0)
        {
            rrb(b);
            tmp_b->cost_b = tmp_b->cost_b + 1;
        }
        if (tmp_b->cost_a > 0 && tmp_b->cost_b > 0)
        {
            rr(a , b);
            tmp_b->cost_a = tmp_b->cost_a - 1;
            tmp_b->cost_b = tmp_b->cost_b - 1;
        }
        if (tmp_b->cost_a > 0 && tmp_b->cost_b == 0)
        {
            ra(a);
            tmp_b->cost_a = tmp_b->cost_a - 1;   
        }
        if (tmp_b->cost_b > 0 && tmp_b->cost_a == 0)
        {
            rb(b);
            tmp_b->cost_b = tmp_b->cost_b - 1;
        }
        if (tmp_b->cost_b == 0 && tmp_b->cost_a == 0)
            pta(a,b);
    }
}

void cost_a(t_list **a, t_list **b)//differencier le cas ou cest vers le bas ou vers le haut 
{
    int taille;
    int mediane;
    t_list  *tmp_b;
    
    taille = ft_lstsize((*a));
    mediane = taille / 2;
    tmp_b = (*b);
   // if ((*b)->target_pos == mediane)
        //si cout de b negatif alors faire negativement et inversement
    while(tmp_b)
    {
        if (tmp_b->target_pos > mediane) // ou >=
            tmp_b->cost_a = tmp_b->target_pos - taille;//negatif
        else
            tmp_b->cost_a = tmp_b->target_pos;
        tmp_b = tmp_b->next;
        
    }
}

int cout_reel (int  cost_a, int cost_b)
{
    int cout;
    
    if (cost_a < 0 && cost_b < 0)
    {
        if (cost_a < cost_b)
            return (cost_a * -1);
        else
            return (cost_b * -1);
    }
    else if (cost_a > 0 && cost_b > 0)
    {
        if (cost_a > cost_b)
            return (cost_a);
        else
            return (cost_b);
    }
    else
    {
        if(cost_a <= 0)
            cout = (cost_a * -1) + cost_b;
        else if (cost_b <= 0)
            cout = cost_a + (cost_b * -1);
        return (cout);
    }
}

int    cout_global (t_list **a, t_list **b) //prendre en compte le cas ou les deux sont negatif
{
    t_list  *tmp_b;
    int taille;
    int cout_1;
    int cout_2;
    int elu;
    
    tmp_b = (*b);
    elu = 0;
  //  i = 0;
    taille = ft_lstsize((*b));
    cout_1 = cout_reel(tmp_b->cost_a, tmp_b->cost_b);
    tmp_b = tmp_b->next;
    while(tmp_b)
    {
        cout_2 = cout_reel(tmp_b->cost_a, tmp_b->cost_b);
        if (cout_1 < 0)
            cout_1 = cout_1 * -1;
        if (cout_2 < 0)
            cout_2 = cout_2 * -1;
        if (cout_2 < cout_1)
        {
            cout_1 = cout_2;
            elu = tmp_b->pos;
        }
        tmp_b = tmp_b->next;
    }
    return(elu); //pour savoir lequelle va etre bouger
    
}


void cost_b(t_list **a, t_list **b)//differencier le cas ou cest vers le bas ou vers le haut 
{
    int taille;
    int mediane;
    t_list *tmp_b;
    
    taille = ft_lstsize((*b));
    mediane = taille / 2;
    tmp_b = (*b);
    while(tmp_b)
    {
        if (tmp_b->pos > mediane)
            tmp_b->cost_b = tmp_b->pos - taille;
        else
            tmp_b->cost_b = tmp_b->pos;
        tmp_b = tmp_b->next;        
    }
   // if ((*b)->target_pos == mediane)
        //si cout de b negatif alors faire negativement et inversement
}


void target_pos(t_list **a, t_list **b) // probleme tmp_a doit revenir au debut
{
    t_list  *tmp_a;
    t_list  *tmp_b;

    tmp_b = (*b);
    tmp_a = (*a);
    while(tmp_b)
    {
        tmp_a = (*a);// est ce que ca resout le probleme ?? donne la tete de serie ou pas sinon devoir coder prev et revenir avant ou faire un tableau a chaque fois
        while(tmp_a->next && (tmp_b->index > tmp_a->index))
            tmp_a = tmp_a->next;
        if (tmp_b->index < tmp_a->index)
            tmp_b->target_pos = tmp_a->pos;
        else
            tmp_b->target_pos = tmp_a->pos - 1;
        tmp_b = tmp_b->next;
    }
}


void pos(t_list **a, t_list **b)
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
        i = 1;
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