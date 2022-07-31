/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:52:29 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/13 19:53:27 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	msg_error(t_list **list_a)
{
	write(2, "Error\n", 6);
	if (*list_a)
		ft_clean(list_a);
	return (0);
}

void	ft_clean(t_list **list_a)
{
	t_list	*liste1;
	t_list	*tmp;

	liste1 = *list_a;
	if (!liste1)
		return ;
	while (liste1)
	{
		tmp = liste1;
		liste1 = liste1->next;
		free(tmp);
	}
	*list_a = NULL;
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
