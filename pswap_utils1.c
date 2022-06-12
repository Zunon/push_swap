/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:21:24 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 17:41:05 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * refactor_args(int *, char ***)
 * --------------------
 * standardizes the given inputs into a format that is usable by our program
 *
 * parameters:
 *  int *: a pointer to an int representing the amount of arguments our program
 *   was given.
 *  char ***: a pointer to the string array in which our arguments are stored
 */
void	refactor_args(int *argc, char ***argv)
{
	int		i;
	char	*accumulator;
	char	*temp;

	i = 1;
	accumulator = malloc(1);
	*accumulator = 0;
	while (i < *argc)
	{
		temp = accumulator;
		accumulator = ft_strjoinsp(temp, (*argv)[i++]);
		free(temp);
	}
	*argv = ft_split(accumulator, ' ');
	*argc = 0;
	while ((*argv)[*argc])
		(*argc)++;
	free(accumulator);
}

/*
 * find_extreme(stack, bool) -> unsigned int
 * --------------------
 * finds an extreme value within the given stack. either the minimum or the
 * maximum, depending on the inputs.
 *
 * parameters:
 *  stack: stack to be searched through
 *  bool: which kind of extreme value we're looking for, a truthy value when
 *   we're looking for the minimum value, and otherwise when we're looking
 *   the maximum value.
 *
 * returns: a pointer to the number found inside the array (mainly used in this
 *  program for its truthiness)
 */
unsigned int	find_extreme(t_stack *stack, unsigned char min)
{
	int				extreme;
	int				i;
	int				extr_ind;

	i = 0;
	extr_ind = -1;
	if (min)
		extreme = 0x7fffffff;
	else
		extreme = 0x80000000;
	while (i <= stack->top)
	{
		if ((min && stack->data[i] < extreme)
			|| (!min && stack->data[i] > extreme))
		{
			extreme = stack->data[i];
			extr_ind = i;
		}
		i++;
	}
	return (extr_ind);
}

/*
 * move_to_top(stack, unsigned int, char)
 * --------------------
 * moves the number at the given index in the given stack to the top of the
 * stack, using rotation or reverse rotation depending on which is faster to
 * reach the top of the stack
 *
 * parameters:
 *  stack: the given stack
 *  unsigned int: index of the value to be moved to the top of the stack
 *  char: name of the stack (either 'a' or 'b')
 */
void	move_to_top(t_stack *stack, unsigned int index, char name)
{
	unsigned char	dir;
	unsigned int	i;

	if (stack->top - index < index + 1)
		i = stack->top - index;
	else
		i = index + 1;
	dir = (i != (index + 1));
	while (i--)
	{
		if (!dir)
			ft_printf("r");
		ft_printf("r%c\n", name);
		rt(dir, stack);
	}
}

/*
 * move_until(stack dest, stack src, char, byte)
 * --------------------
 * moves extreme values from one stack to the other until a given amount of
 * numbers remain in the source stack. extreme values are minimums in a, and
 * maximums in b.
 *
 * parameters:
 *  stack dest: destination stack to be moved into
 *  stack src: source stack to be moved from
 *  char: name of the destination stack (either 'a' or 'b')
 *  byte: the amount of numbers that should remain in the source stack to stop
 */
void	move_until(t_stack *dest, t_stack *src, char name,
	unsigned char until)
{
	int				extr_ind;
	unsigned char	min;
	char			srcname;

	if (name != 'a')
	{
		min = 1;
		srcname = 'a';
	}
	else
	{
		min = 0;
		srcname = 'b';
	}
	while (src->top >= until)
	{
		extr_ind = find_extreme(src, min);
		move_to_top(src, extr_ind, srcname);
		ft_printf("p%c\n", name);
		pt(dest, src);
	}
}

/*
 * find_half(stack, int *, int chunksize, int i) -> int *
 * --------------------
 * finds the closest number to the top, and the closest to the bottom that are
 * both in the given chunk of the given array, in the stack.
 *
 * parameters:
 *  stack: the given stack to be searched through
 *  int *: the given sorted array to be checked against
 *  int chunksize: the size of the chunk in the given array
 *  int i: the index of the chunk to be checked in
 *
 * returns: an integer array containing the index of the number closest to the
 *  top, and the index of the number closest to the bottom.
 */
int	*find_half(t_stack *stack, int *list, int chunksize, int i)
{
	int	j;
	int	*result;

	result = ft_calloc(2, sizeof(int));
	result[0] = -1;
	result[1] = -1;
	j = stack->top + 1;
	while (--j >= (stack->top) / 2)
	{
		if (tabint(list + (i * chunksize), stack->data[j], chunksize))
		{
			result[0] = j;
			break ;
		}
	}
	j = -1;
	while (++j <= (stack->top) / 2)
	{
		if (tabint(list + (i * chunksize), stack->data[j], chunksize))
		{
			result[1] = j;
			break ;
		}
	}
	return (result);
}
