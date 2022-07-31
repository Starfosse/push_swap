/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:28:34 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:28:34 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_stdin_operations(t_list **list_a, t_list **list_b)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!(do_instructs1(line, list_a, list_b)))
		{
			free(line);
			ft_clean(list_a);
			ft_clean(list_b);
			write(2, "Error\n", 6);
			exit(0);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
}

void	check_sort(t_list *list_a, t_list *list_b)
{
	if (!(in_order(list_a)) && !list_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 1 || ft_strcmp(argv[0], "./checker"))
		return (msg_error(&list_a));
	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (!one_arg(&list_a, argv[1]))
			return (msg_error(&list_a));
	}
	else
	{
		if (!multiple_args(&list_a, argv))
			return (msg_error(&list_a));
	}
	read_stdin_operations(&list_a, &list_b);
	check_sort(list_a, list_b);
	ft_clean(&list_a);
	ft_clean(&list_b);
	return (0);
}
