/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:53:11 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 17:23:43 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * swap(int *first, int *second)
 * --------------------
 * swaps the values of the two int addresses given to it
 *
 * parameters:
 *  int *first: pointer to the first number to be swapped
 *  int *second: pointer to the second number to be swapped
 */
void	swap(int *first, int *second)
{
	int	third;

	third = *first;
	*first = *second;
	*second = third;
}

/*
 * partition(int *, int) -> int
 * --------------------
 * partitions an array (for quicksort purposes), putting every element bigger
 * than the pivot after it, and every element smaller than it before it.
 *
 * parameters:
 *  int *: array of integers to be partitioned
 *  int: amuont of numbers in that array
 *
 * returns: index of the pivot after partitioning
 */
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

/*
 * ft_sort_int_tab(int *, int)
 * --------------------
 * sorts the given array using an implementation of quicksort
 *
 * parameters:
 *  int *: array to be sorted
 *  int: amount of numbers in the given array
 */
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

/*
 * is_sorted(stack) -> bool
 * --------------------
 * checks whether or not the stack is sorted, and outputs such truthy value
 *
 * parameters:
 *  stack: stack to be checked
 *
 * returns: truthy value if stack is sorted, falsy value otherwise
 */
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

/*
 * tabint(int *, int num, int n)
 * --------------------
 * checks if a given number exists in the given array
 *
 * parameters:
 *  int *: the array to be searched through
 *  int num: the number to be searched for
 *  int n: the amount of numbers in the array
 *
 * returns: a pointer to the number found inside the array (mainly used in this
 *  program for its truthiness)
 */
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
