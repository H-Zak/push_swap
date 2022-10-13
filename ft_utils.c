/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:14:32 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/13 17:19:41 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	j;
	long	num;

	i = 0;
	j = 1;
	num = 0;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		j = -1;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * j);
}

int	ft_atoi(const char *nptr)
{
	int i;
	int j;
	int num;

	i = 0;
	j = 1;
	num = 0;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		j = -1;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * j);
}

int	stack_size(t_list *a) //je pourrais possiblement en avoir besoin
{
	int	size;
	size = 0;
	while (a && a->next)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}