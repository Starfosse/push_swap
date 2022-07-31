/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:16 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:31:16 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_next_sup(t_list **list_a, long int nbr)
{
	t_list		*liste;
	long int	min;
	long int	total;

	liste = *list_a;
	total = 0;
	min = 2147483647;
	while (liste->next != NULL)
	{
		if ((long int)liste->content > nbr)
		{
			total = (long int) liste->content;
			if (total < min)
				min = total;
		}
		liste = liste->next;
		if ((long int)liste->content > nbr)
		{
			total = (long int) liste->content;
			if (total < min)
				min = total;
		}
	}
	return (min);
}

long int	ft_next_inf(t_list **list_a, long int nbr)
{
	t_list		*liste;
	long int	min;
	long int	total;

	liste = *list_a;
	total = 0;
	min = -2147483647;
	while (liste->next != NULL)
	{
		if ((long int)liste->content < nbr)
		{
			total = (long int) liste->content;
			if (total > min)
				min = total;
		}
		liste = liste->next;
		if ((long int)liste->content < nbr)
		{
			total = (long int) liste->content;
			if (total > min)
				min = total;
		}
	}
	return (min);
}

int	ft_find_smaller(t_list **list_a)
{
	t_list		*liste;
	long int	nbr;

	nbr = 2147483647;
	liste = *list_a;
	while (liste->next)
	{
		if ((long int)liste->content < nbr)
			nbr = (long int) liste->content;
		liste = liste->next;
		if ((long int)liste->content < nbr)
			nbr = (long int) liste->content;
	}
	if (nbr == 2147483647 && !liste->next)
		nbr = (long int) liste->content;
	return (nbr);
}

void	ft_smallest(t_list **list_b)
{
	t_list	*liste2;

	liste2 = *list_b;
	if (ft_choice_rotate(&liste2, ft_find_smaller(&liste2)))
		while ((long int) liste2->content != ft_find_smaller(&liste2))
			ft_rotate(&liste2, "ra\n");
	else
		while ((long int) liste2->content != ft_find_smaller(&liste2))
			ft_reverse_rotate(&liste2, "rra\n");
}

int	ft_choice_rotate(t_list **list_a, long int nbr)
{
	t_list	*liste1;
	int		count;
	int		i;

	i = 0;
	liste1 = *list_a;
	count = ft_lstsize(liste1);
	while (liste1->next)
	{
		if ((long int) liste1->content == nbr && i < (count / 2))
			return (1);
		i++;
		liste1 = liste1->next;
	}
	return (0);
}
