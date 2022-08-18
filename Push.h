/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:29:55 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/08/18 16:07:19 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

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
	struct	s_list	*prev;
}			t_list;

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
//void	ft_lastadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int	ft_atoi(const char *nptr);
void	ft_lstadd_front(t_list **lst, t_list *new);


#endif
