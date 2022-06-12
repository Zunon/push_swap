/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:21:24 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 15:41:46 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
