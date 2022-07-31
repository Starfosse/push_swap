/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:30:55 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:30:55 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a_b(t_list **list_a, t_list **list_b)
{
	ft_reverse_rotate(list_a, "");
	ft_reverse_rotate(list_b, "rrr\n");
}

void	ft_rotate_a_b(t_list **list_a, t_list **list_b)
{
	ft_rotate(list_a, "");
	ft_rotate(list_b, "rr\n");
}

void	ft_swap_a_b(t_list **list_a, t_list **list_b)
{
	ft_swap(list_a, "");
	ft_swap(list_b, "ss\n");
}
