/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:29:09 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:29:09 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_argv(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

long int	ft_latoi(const char	*nptr)
{
	int			i;
	int			neg;
	long int	nbr;

	if (!nptr)
		return (0);
	i = 0;
	neg = 1;
	nbr = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (!(ft_isdigit(nptr[i])))
		return (2147483649);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nptr[i] - '0') + (nbr * 10);
		i++;
	}
	return (nbr * neg);
}

int	ft_check_int(long int content)
{
	if (content > 2147483647 || content < -2147483648)
		return (0);
	return (1);
}

int	ft_check_list(t_list *list_a)
{
	t_list	*tmp;

	while (list_a->next)
	{
		tmp = list_a->next;
		while (tmp)
		{
			if (tmp->content == list_a->content)
				return (0);
			tmp = tmp->next;
		}
		list_a = list_a->next;
	}
	return (1);
}

int	in_order(t_list *list_a)
{
	int	i;
	int	j;

	j = 0;
	i = ft_lstsize(list_a);
	while (j < i - 1)
	{
		j++;
		if ((long int)list_a->content > (long int)list_a->next->content)
			return (1);
		list_a = list_a->next;
	}
	return (0);
}
