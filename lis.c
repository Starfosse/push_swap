/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:29:43 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:29:43 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_replace(long int *lis, int left, int right, long int key)
{
	int	mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

long int	*lis(long int *A, int size)
{
	int			i;
	long int	*lis;
	long int	*index;
	int			lis_length;

	lis_length = -1;
	index = (long int *) malloc (sizeof(long int) * size);
	lis = (long int *) malloc (sizeof(long int) * size);
	ft_bzero(index, sizeof(long int));
	ft_bzero(lis, sizeof(long int));
	i = 0;
	lis[0] = A[0];
	while (++i < size)
		lis[i] = INT_INF;
	i = 0;
	while (++i < size)
	{
		index[i] = search_replace(lis, 0, i, A[i]);
		if (lis_length < index[i])
			lis_length = index[i];
	}
	free(lis);
	return (lis2(A, size, lis_length, index));
}

long int	*lis2(long int *A, int size, int lis_length, long int *index)
{
	int			tmp;
	long int	*answer;
	int			i;

	tmp = 0;
	answer = (long int *) malloc (sizeof(long int) * (lis_length + 1));
	ft_bzero(answer, sizeof(long int));
	if (!answer)
	{
		free(index);
		return (NULL);
	}
	i = size - 1;
	tmp = lis_length;
	while (i >= 0)
	{
		if (index[i] == tmp)
		{
			answer[tmp] = A[i];
			--tmp;
		}
		i--;
	}
	free(index);
	return (answer);
}

int	lis3(long int *A, int size)
{
	int			i;
	long int	*lis;
	long int	*index;
	int			lis_length;

	lis_length = -1;
	index = (long int *) malloc (sizeof(long int) * size);
	lis = (long int *) malloc (sizeof(long int) * size);
	ft_bzero(index, sizeof(long int));
	ft_bzero(lis, sizeof(long int));
	i = 0;
	lis[0] = A[0];
	while (++i < size)
		lis[i] = INT_INF;
	i = 0;
	while (++i < size)
	{
		index[i] = search_replace(lis, 0, i, A[i]);
		if (lis_length < index[i])
			lis_length = index[i];
	}
	free (lis);
	free (index);
	return (lis_length);
}
