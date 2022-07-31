/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:29:29 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 19:28:20 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean(t_list **list_a)
{
	t_list	*liste1;
	t_list	*tmp;

	liste1 = *list_a;
	if (!liste1)
		return ;
	while (liste1)
	{
		tmp = liste1;
		liste1 = liste1->next;
		free(tmp);
	}
	*list_a = NULL;
}

void	clean_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	msg_error(t_list **list_a)
{
	write(2, "Error\n", 6);
	if (*list_a)
		ft_clean(list_a);
	return (0);
}
