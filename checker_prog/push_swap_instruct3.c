/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:03 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:31:10 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap1(t_list **list_a)
{
	t_list	*tmp;
	void	*tmp2;

	tmp = *list_a;
	if (!tmp)
	{
		return ;
	}
	if (!tmp->next || !tmp->content)
		return ;
	tmp2 = tmp->content;
	tmp->content = tmp->next->content;
	tmp = tmp->next;
	tmp->content = tmp2;
}

void	ft_rotate1(t_list **list_a)
{
	t_list	*tmp;
	void	*tmp2;

	tmp = *list_a;
	if (!tmp)
	{
		return ;
	}
	tmp2 = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = tmp2;
	tmp = *list_a;
}

void	ft_reverse_rotate1(t_list **list_a)
{
	t_list	*list;
	void	*tmp3;
	void	*tmp2;

	list = *list_a;
	if (!list)
	{
		return ;
	}
	while (list->next)
		list = list->next;
	tmp3 = list->content;
	list = *list_a;
	while (list->next)
	{
		tmp2 = list->content;
		list->content = tmp3;
		tmp3 = tmp2;
		list = list->next;
	}
	list->content = tmp3;
}

void	ft_push1(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	t_list	*tmp3;

	tmp3 = *list_a;
	if (!tmp3)
		return ;
	tmp3 = tmp3->next;
	tmp = *list_a;
	if (!*list_b)
	{
		tmp->next = NULL;
		*list_b = tmp;
	}
	else
	{
		tmp->next = *list_b;
		*list_b = tmp;
	}
	*list_a = tmp3;
}
