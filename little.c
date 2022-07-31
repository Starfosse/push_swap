/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:29:47 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:29:47 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_little(t_list **list_a)
{
	t_list	*l1;

	l1 = *list_a;
	if ((long int)l1->content > (long int)l1->next->content
		&& (long int)l1->next->content < (long int)l1->next->next->content
		&& (long int)l1->content < (long int)l1->next->next->content)
		ft_swap(list_a, "sa\n");
	else if ((long int)l1->content > (long int)l1->next->content
		&& (long int)l1->next->content > (long int)l1->next->next->content)
	{
		ft_swap(list_a, "sa\n");
		ft_reverse_rotate(list_a, "rra\n");
	}
	else if ((long int)l1->content > (long int)l1->next->content
		&& (long int)l1->next->content < (long int)l1->next->next->content)
		ft_rotate(list_a, "ra\n");
	else if ((long int)l1->content < (long int)l1->next->content
		&& (long int)l1->content < (long int)l1->next->next->content)
	{
		ft_swap(list_a, "sa\n");
		ft_rotate(list_a, "ra\n");
	}
	else if ((long int)l1->content < (long int)l1->next->content
		&& (long int)l1->next->content > (long int)l1->next->next->content)
		ft_reverse_rotate(list_a, "rra\n");
}

void	ft_sort_little3(t_list **list_a, t_list **list_b)
{
	t_list	*liste2;
	int		count;

	liste2 = *list_b;
	while (liste2)
	{
		count = ft_posa(list_a, (long int) liste2->content);
		if (!ft_is_smallest(list_a, (long int)liste2->content))
			count = ft_next_small(list_a);
		while (count > 0)
		{
			ft_rotate(list_a, "ra\n");
			count--;
		}
		while (count < 0)
		{
			ft_reverse_rotate(list_a, "rra\n");
			count++;
		}
		if (count == 0)
			ft_push(list_b, list_a, "pa\n");
		liste2 = *list_b;
	}
}

void	ft_sort_little2(t_list **list_a, t_list **list_b)
{
	ft_push(list_a, list_b, "pb\n");
	ft_push(list_a, list_b, "pb\n");
	if (in_order(*list_a))
		ft_sort_little(list_a);
	ft_sort_little3(list_a, list_b);
}

int	ft_one_last(t_list **list_a, long int nbr)
{
	t_list	*liste1;
	t_list	*liste2;

	liste2 = *list_a;
	liste1 = *list_a;
	while (liste2)
		liste2 = liste2->next;
	if (nbr < (long int) liste1->content && nbr > (long int)liste2->content)
		return (1);
	return (0);
}

int	ft_one_last2(t_list **list_a, long int nbr)
{
	t_list	*liste1;
	t_list	*liste2;

	liste2 = *list_a;
	liste1 = *list_a;
	while (liste2)
		liste2 = liste2->next;
	if (nbr < (long int) liste1->content && nbr > (long int)liste1->content)
		return (1);
	return (0);
}
