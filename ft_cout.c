/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:28:58 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/20 15:44:37 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void     cost_b(t_list **a, t_list **b);
int    cout_global (t_list **a, t_list **b);
void     cost_a(t_list **a, t_list **b);
int cout_reel (int  cost_a, int cost_b);

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
        // if (tmp_b->target_pos == (taille - 1))
        //     tmp_b->cost_a = 0;
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
    return(elu);
}


void cost_b(t_list **a, t_list **b)
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
}