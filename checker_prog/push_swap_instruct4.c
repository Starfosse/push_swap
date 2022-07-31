/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:08 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:31:09 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_reverse_rotate_a_b1(t_list **list_a, t_list **list_b)
{
	if (*list_a)
		ft_reverse_rotate1(list_a);
	if (*list_b)
		ft_reverse_rotate1(list_b);
}

void	ft_rotate_a_b1(t_list **list_a, t_list **list_b)
{
	if (*list_a)
		ft_rotate1(list_a);
	if (*list_b)
		ft_rotate1(list_b);
}

void	ft_swap_a_b1(t_list **list_a, t_list **list_b)
{
	if (*list_a)
		ft_swap1(list_a);
	if (*list_b)
		ft_swap1(list_b);
}
