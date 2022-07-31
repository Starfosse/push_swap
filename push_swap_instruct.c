/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:30:28 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:30:28 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list_a, char *str)
{
	t_list	*tmp;
	void	*tmp2;

	ft_putstr(str);
	tmp = *list_a;
	tmp2 = tmp->content;
	tmp->content = tmp->next->content;
	tmp = tmp->next;
	tmp->content = tmp2;
}

void	ft_rotate(t_list **list_a, char *str)
{
	t_list	*tmp;
	void	*tmp2;

	ft_putstr(str);
	tmp = *list_a;
	tmp2 = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = tmp2;
	tmp = *list_a;
}

void	ft_reverse_rotate(t_list **list_a, char *str)
{
	t_list	*list;
	void	*tmp3;
	void	*tmp2;

	ft_putstr(str);
	list = *list_a;
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

void	ft_push(t_list **list_a, t_list **list_b, char *str)
{
	t_list	*tmp;
	t_list	*tmp3;

	ft_putstr(str);
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
