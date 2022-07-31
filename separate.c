/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:32:06 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:32:06 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_more_answer(t_list *liste1, long int *answer, int length)
{
	while (liste1)
	{
		if (is_in_answer(liste1, answer, length))
			return (1);
		liste1 = liste1->next;
	}
	return (0);
}

int	is_in_answer(t_list *liste1, long int *answer, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (answer[i] == (long int) liste1->content)
			return (1);
		i++;
	}
	return (0);
}

void	ft_separate(t_list **la, t_list **lb, long int *answer, int l)
{
	t_list	*liste1;
	int		count;

	liste1 = *la;
	count = ft_lstsize(liste1) - l;
	while (count > 0)
	{
		if (!is_in_answer(liste1, answer, l))
		{
			ft_push(la, lb, "pb\n");
			count--;
		}
		else
			ft_rotate(&liste1, "ra\n");
		liste1 = *la;
	}
	return ;
}
