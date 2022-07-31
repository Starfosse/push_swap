/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:29:34 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:29:34 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_instructs1(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "sa\n")))
	{
		ft_swap1(list_a);
		return (1);
	}
	if (!(ft_strcmp(line, "ra\n")))
	{
		ft_rotate1(list_a);
		return (1);
	}
	if (!(ft_strcmp(line, "rra\n")))
	{
		ft_reverse_rotate1(list_a);
		return (1);
	}
	return (do_instructs2(line, list_a, list_b));
}

int	do_instructs2(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "sb\n")))
	{
		ft_swap1(list_b);
		return (1);
	}
	if (!(ft_strcmp(line, "rb\n")))
	{
		ft_rotate1(list_b);
		return (1);
	}
	if (!(ft_strcmp(line, "rrb\n")))
	{
		ft_reverse_rotate1(list_b);
		return (1);
	}
	return (do_instructs3(line, list_a, list_b));
}

int	do_instructs3(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "ss\n")))
	{
		ft_swap_a_b1(list_a, list_b);
		return (1);
	}
	if (!(ft_strcmp(line, "pa\n")))
	{
		ft_push1(list_b, list_a);
		return (1);
	}
	if (!(ft_strcmp(line, "pb\n")))
	{
		ft_push1(list_a, list_b);
		return (1);
	}
	return (do_instructs4(line, list_a, list_b));
}

int	do_instructs4(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "rr\n")))
	{
		ft_rotate_a_b1(list_a, list_b);
		return (1);
	}
	if (!(ft_strcmp(line, "rrr\n")))
	{
		ft_reverse_rotate_a_b1(list_a, list_b);
		return (1);
	}
	return (0);
}
