/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:29:55 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/08/25 18:48:32 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
    int    content;
    struct	s_list	*next;
	struct	s_list	*prev; //check not use yet
}			t_list;

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
int     ft_atoi(const char *nptr);
void	ft_lastadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ptb (t_list **a, t_list **b);
void	pta (t_list **a, t_list **b);
void	rra (t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	ra(t_list **a);
void    rb(t_list **b);
void	rr (t_list **a, t_list **b);
void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
int	    stack_size(t_list *a);
void	ft_sort_int_tab(int *tab, int size);

#endif
