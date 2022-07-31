/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:52:52 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/13 20:03:13 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		return (0);
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

int	ft_check_argv(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

int	ft_check_int(long int content)
{
	if (content > 2147483647 || content < -2147483648)
		return (0);
	return (1);
}

int	ft_check_list(t_list *list_a)
{
	t_list	*tmp;

	while (list_a->next)
	{
		tmp = list_a->next;
		while (tmp)
		{
			if (tmp->content == list_a->content)
				return (0);
			tmp = tmp->next;
		}
		list_a = list_a->next;
	}
	return (1);
}
