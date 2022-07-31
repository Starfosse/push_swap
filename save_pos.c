/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:32:03 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:32:03 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_posa(t_list **list_a, long int nbr)
{
	t_list	*l1;
	int		count;
	int		i;

	count = 0;
	i = 1;
	l1 = *list_a;
	if (!ft_is_biggest(list_a, nbr))
		return (ft_next_big(list_a));
	else if (!ft_is_smallest(list_a, nbr))
		return (ft_next_small(list_a));
	while (l1->next)
	{
		if (nbr > (long int) l1->content && nbr < (long int) l1->next->content)
			count = i;
		i++;
		l1 = l1->next;
	}
	i = ft_lstsize(*list_a);
	if (count > i / 2)
		count = count - i;
	return (count);
}

int	ft_posb(t_list **list_b, long int nbr)
{
	t_list	*liste2;
	int		count;
	int		i;

	count = 0;
	i = 0;
	liste2 = *list_b;
	while (liste2)
	{
		if ((long int) liste2->content == nbr)
			count = i;
		i++;
		liste2 = liste2->next;
	}
	i = ft_lstsize(*list_b);
	if (count > i / 2)
		count = count - i;
	return (count);
}

int	**ft_save_pos(t_list **list_a, t_list **list_b)
{
	t_list	*liste2;
	int		**tab;
	int		i;

	i = 0;
	liste2 = *list_b;
	tab = (int **) malloc (sizeof(int *) * ft_lstsize(*list_b));
	while (liste2)
	{
		tab[i] = (int *) malloc (sizeof(int *) * 2);
		tab[i][0] = ft_posa(list_a, (long int) liste2->content);
		tab[i++][1] = ft_posb(list_b, (long int) liste2->content);
		liste2 = liste2->next;
	}
	return (tab);
}
