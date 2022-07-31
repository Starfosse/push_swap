/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:28 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:31:28 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	one_arg(t_list **list, char *argv)
{
	int		i;
	char	**split;
	t_list	*tmp;

	i = 0;
	split = ft_split(argv, ' ');
	if (!split[i])
	{
		clean_split(split);
		return (1);
	}
	while (split[i])
	{
		if (!ft_check_argv(split[i]) || !ft_check_int(ft_latoi(split[i])))
		{
			clean_split(split);
			return (0);
		}
		tmp = ft_lstnew((void *) ft_latoi(split[i++]));
		ft_lstadd_back(list, tmp);
	}
	clean_split(split);
	if (!ft_check_list(*list))
		return (0);
	return (1);
}

int	multiple_args(t_list **list, char **argv)
{
	int		i;
	t_list	*tmp;

	i = 1;
	while (argv[i])
	{
		if (!ft_check_argv(argv[i]) || !ft_check_int(ft_latoi(argv[i])))
			return (0);
		tmp = ft_lstnew((void *) ft_latoi(argv[i++]));
		ft_lstadd_back(list, tmp);
	}
	if (!ft_check_list(*list))
		return (0);
	return (1);
}

void	ft_push_swap(t_list *list_a)
{
	t_list	*list_b;
	int		i;

	list_b = NULL;
	i = ft_lstsize(list_a);
	if (i == 1)
		return ;
	if (i == 2 && (long int)list_a->content > (long int)list_a->next->content)
		ft_swap(&list_a, "sa\n");
	else if (i == 3)
		ft_sort_little(&list_a);
	else if (i == 5)
	{
		ft_sort_little2(&list_a, &list_b);
		ft_smallest_little(&list_a);
	}
	else
	{
		ft_sort_little4(&list_a, &list_b);
		ft_smallest_little(&list_a);
	}
}
