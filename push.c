/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:59 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:31:59 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_positif(int *tab, t_list **list_a, t_list **list_b)
{
	while (tab[0] > 0 && tab[1] > 0)
	{
		ft_rotate_a_b(list_a, list_b);
		tab[0] = tab[0] - 1;
		tab[1] = tab[1] - 1;
	}
	while (tab[0] > 0)
	{
		ft_rotate(list_a, "ra\n");
		tab[0] = tab[0] - 1;
	}
	while (tab[1] > 0)
	{
		ft_rotate(list_b, "rb\n");
		tab[1] = tab[1] - 1;
	}
}

void	ft_negatif(int *tab, t_list **list_a, t_list **list_b)
{
	while (tab[0] < 0 && tab[1] < 0)
	{
		ft_reverse_rotate_a_b(list_a, list_b);
		tab[0] = tab[0] + 1;
		tab[1] = tab[1] + 1;
	}
	while (tab[0] < 0)
	{
		ft_reverse_rotate(list_a, "rra\n");
		tab[0] = tab[0] + 1;
	}
	while (tab[1] < 0)
	{
		ft_reverse_rotate(list_b, "rrb\n");
		tab[1] = tab[1] + 1;
	}
}

void	ft_negatif_positif(int *tab, t_list **list_a, t_list **list_b)
{
	while (tab[0] < 0)
	{
		ft_reverse_rotate(list_a, "rra\n");
		tab[0] = tab[0] + 1;
	}
	while (tab[1] < 0)
	{
		ft_reverse_rotate(list_b, "rrb\n");
		tab[1] = tab[1] + 1;
	}
	while (tab[0] > 0)
	{
		ft_rotate(list_a, "ra\n");
		tab[0] = tab[0] - 1;
	}
	while (tab[1] > 0)
	{
		ft_rotate(list_b, "rb\n");
		tab[1] = tab[1] - 1;
	}
}
