/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:54 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/10 21:31:05 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap2(int *tab, t_list **list_a, t_list **list_b)
{
	if (tab[0] >= 0 && tab[1] >= 0)
		ft_positif(tab, list_a, list_b);
	if (tab[0] <= 0 && tab[1] <= 0)
		ft_negatif(tab, list_a, list_b);
	if ((tab[0] > 0 && tab[1] < 0)
		|| (tab[0] < 0 && tab[1] > 0))
		ft_negatif_positif(tab, list_a, list_b);
	ft_push(list_b, list_a, "pa\n");
}

void	ft_merge(t_list **list_a, t_list **list_b)
{
	int		**tab;
	int		j;
	int		count;
	int		size;

	count = ft_lstsize(*list_b);
	while (count > 0)
	{
		size = ft_lstsize(*list_b);
		tab = ft_save_pos(list_a, list_b);
		j = ft_choice(tab, size);
		ft_swap2(tab[j], list_a, list_b);
		clean_tab(tab, size);
		count--;
	}
	ft_smallest(list_a);
}

void	push_swap1(t_list *list_a)
{
	long int	*answer;
	t_list		*list_b;
	int			length;
	long int	*tab;

	answer = NULL;
	length = 0;
	list_b = NULL;
	tab = list_to_tab(list_a, ft_lstsize(list_a));
	list_b = NULL;
	ft_smallest(&list_a);
	answer = lis(tab, ft_lstsize(list_a));
	length = lis3(tab, ft_lstsize(list_a));
	free(tab);
	ft_separate(&list_a, &list_b, answer, length);
	free(answer);
	ft_merge(&list_a, &list_b);
	ft_clean(&list_b);
}

void	ft_choice_swap(t_list *list_a)
{
	int	i;

	if (!in_order(list_a))
	{
		ft_clean(&list_a);
		return ;
	}
	i = ft_lstsize(list_a);
	if (i <= 5)
		ft_push_swap(list_a);
	else
		push_swap1(list_a);
	ft_clean(&list_a);
}
