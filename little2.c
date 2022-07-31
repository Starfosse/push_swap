/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:30:08 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:30:23 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_smallest(t_list **list_a, long int nbr)
{
	t_list	*liste1;

	liste1 = *list_a;
	while (liste1)
	{
		if (nbr > (long int) liste1->content)
			return (1);
		liste1 = liste1->next;
	}
	return (0);
}

void	ft_smallest_little2(t_list **list_a, int count)
{
	while (count < 0)
	{
		count++;
		ft_reverse_rotate(list_a, "rra\n");
	}
	while (count > 0)
	{
		count--;
		ft_rotate(list_a, "ra\n");
	}
}

void	ft_smallest_little(t_list **list_a)
{
	long int	smallest;
	t_list		*liste1;
	int			i;
	int			count;

	count = 0;
	liste1 = *list_a;
	smallest = ft_find_smaller(list_a);
	while ((long int) liste1->content != smallest)
	{
		liste1 = liste1->next;
		count++;
	}
	i = ft_lstsize(*list_a);
	if (count > i / 2)
		count = count - i;
	ft_smallest_little2(list_a, count);
}

void	ft_sort_little5(t_list **list_a, t_list **list_b)
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

void	ft_sort_little4(t_list **list_a, t_list **list_b)
{
	ft_push(list_a, list_b, "pb\n");
	if (in_order(*list_a))
		ft_sort_little(list_a);
	ft_sort_little5(list_a, list_b);
}
