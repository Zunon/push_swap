/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:53:11 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 13:23:07 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *first, int *second)
{
	int	third;

	third = *first;
	*first = *second;
	*second = third;
}

int	partition(int *tab, int size)
{
	int	pivot;
	int	current;
	int	correct;

	pivot = tab[size - 1];
	current = -1;
	correct = -1;
	while (++current <= size - 1)
		if (tab[current] < pivot)
			swap(&tab[++correct], &tab[current]);
	swap(&tab[++correct], &tab[size - 1]);
	return (correct);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	partition_index;

	if (0 < (size - 1))
	{
		partition_index = partition(tab, size);
		ft_sort_int_tab(tab, partition_index);
		ft_sort_int_tab(&tab[partition_index + 1], size - partition_index - 1);
	}
}

unsigned char	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->top >= 1)
	{
		i = 0;
		while (i < stack->top)
		{
			if (stack->data[i] < stack->data[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int	*tabint(int *list, int num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (list[i] == num)
			return (list + i);
		i++;
	}
	return (0);
}
