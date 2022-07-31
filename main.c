/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:30:20 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:30:21 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*list;

	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[0], "./push_swap"))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	list = NULL;
	if (argc == 2)
	{
		if (!one_arg(&list, argv[1]))
			return (msg_error(&list));
	}
	else
	{
		if (!multiple_args(&list, argv))
			return (msg_error(&list));
	}
	ft_choice_swap(list);
	return (0);
}
