/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:40:09 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 13:19:45 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	st(t_stack *stack)
{
	if (stack->top >= 1)
		swap(&(stack->data[stack->top]), &(stack->data[stack->top - 1]));
}

void	pt(t_stack *dst, t_stack *src)
{
	if (src->top >= 0)
		dst->data[++(dst->top)] = src->data[(src->top)--];
}

void	rr(unsigned char direction, t_stack *a, t_stack *b)
{
	rt(direction, a);
	rt(direction, b);
}

void	ss(t_stack *a, t_stack *b)
{
	st(a);
	st(b);
}
