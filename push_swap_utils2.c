/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:21 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:31:21 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_biggest(t_list **list_a, long int nbr)
{
	t_list	*liste1;

	liste1 = *list_a;
	while (liste1)
	{
		if (nbr < (long int) liste1->content)
			return (1);
		liste1 = liste1->next;
	}
	return (0);
}

int	ft_next_big(t_list **list_a)
{
	t_list		*liste1;
	long int	count;
	int			i;
	int			j;

	liste1 = *list_a;
	count = -2147483647;
	i = 1;
	j = 0;
	while (liste1)
	{
		if (count < (long int) liste1->content)
		{
			count = (long int) liste1->content;
			j = i;
		}
		i++;
		liste1 = liste1->next;
	}
	i = ft_lstsize(*list_a);
	if (j > i / 2)
		j = j - i;
	return (j);
}

int	ft_next_small(t_list **list_a)
{
	t_list		*liste1;
	long int	count;
	int			i;
	int			j;

	liste1 = *list_a;
	count = 2000;
	i = 0;
	j = 0;
	while (liste1)
	{
		if (count > (long int) liste1->content)
		{
			count = (long int) liste1->content;
			j = i;
		}
		i++;
		liste1 = liste1->next;
	}
	i = ft_lstsize(*list_a);
	if (j > i / 2)
		j = j - i;
	return (j);
}

long int	*list_to_tab(t_list *list_a, int size)
{
	int			i;
	long int	*tab;

	tab = (long int *) malloc (sizeof (long int) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = (long int) list_a->content;
		i++;
		list_a = list_a->next;
	}
	return (tab);
}
