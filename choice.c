/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:29:19 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:29:19 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(int i, int j)
{
	if (i < 0)
		i *= -1;
	if (j < 0)
		j *= -1;
	if (j > i)
		return (j);
	if (i > j)
		return (i);
	if (i == j)
		return (i);
	return (0);
}

int	ft_count2(int i, int j)
{
	int	count;

	count = 0;
	if (i > 0 && j < 0)
		j *= -1;
	else if (i < 0 && j > 0)
		i *= -1;
	count = i + j;
	return (count);
}

int	ft_choice(int **tab, int size)
{
	int	i;
	int	j;
	int	total;
	int	count;

	i = -1;
	j = 0;
	total = 2000;
	count = 0;
	while (++i < size)
	{
		if (tab[i][0] >= 0 && tab[i][1] >= 0)
			count = ft_count(tab[i][0], tab[i][1]);
		else if (tab[i][0] <= 0 && tab[i][1] <= 0)
			count = ft_count(tab[i][0], tab[i][1]);
		else if ((tab[i][0] >= 0 && tab[i][1] <= 0) ||
			(tab[i][0] <= 0 && tab[i][1] >= 0))
			count = ft_count2(tab[i][0], tab[i][1]);
		if (count < total)
		{
			total = count;
			j = i;
		}
	}
	return (j);
}
