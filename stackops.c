/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:40:09 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 16:52:15 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * rt(bool, stack)
 * --------------------
 * rotates a given stack in a given direction
 *
 * parameters:
 *  bool: direction of rotation, true is normal direction, false is reverse
 *   rotation.
 *  stack: the given stack to be rotated
 */
void	rt(unsigned char direction, t_stack *stack)
{
	int	i;

	if (stack->top >= 1)
	{
		if (direction)
		{
			i = 1;
			while (i <= stack->top)
				swap(stack->data, &(stack->data[i++]));
		}
		else
		{
			i = stack->top - 1;
			while (i >= 0)
				swap(&stack->data[stack->top], &stack->data[i--]);
		}
	}
}

/*
 * st(stack)
 * --------------------
 * swaps the top two elements of the given stack
 *
 * parameters:
 *  stack: the given stack to be operated on
 */
void	st(t_stack *stack)
{
	if (stack->top >= 1)
		swap(&(stack->data[stack->top]), &(stack->data[stack->top - 1]));
}

/*
 * pt(stack dst, stack src)
 * --------------------
 * pushes the top of one stack into the other
 *
 * parameters:
 *  stack dst: destination stack to be pushed into
 *  stack src: source stack to be pushed from
 */
void	pt(t_stack *dst, t_stack *src)
{
	if (src->top >= 0)
		dst->data[++(dst->top)] = src->data[(src->top)--];
}

/*
 * rr(bool, stack a, stack b)
 * --------------------
 * rotates both stacks in the given direction
 *
 * parameters:
 *  bool: direction of rotation, see rt(bool, stack)
 *  stack a: one of the stacks
 *  stack b: another one of the stacks
 */
void	rr(unsigned char direction, t_stack *a, t_stack *b)
{
	rt(direction, a);
	rt(direction, b);
}

/*
 * ss(stack a, stack b)
 * --------------------
 * swaps the top two numbers of both stacks
 *
 * parameters:
 *  stack a: one of the stacks
 *  stack b: another one of the stacks
 */
void	ss(t_stack *a, t_stack *b)
{
	st(a);
	st(b);
}
