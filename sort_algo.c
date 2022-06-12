/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:15:30 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 14:52:53 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	patelsort(t_stack *stack)
{
	if (stack->top == 2)
	{
		if (is_sorted(stack))
			return ;
		if (stack->data[0] > stack->data[1] && stack->data[0] < stack->data[2])
		{
			ft_printf("ra\n");
			rt(1, stack);
		}
		else if (stack->data[2] > stack->data[0]
			&& stack->data[2] < stack->data[1])
		{
			ft_printf("rra\n");
			rt(0, stack);
		}
		else
		{
			ft_printf("sa\n");
			st(stack);
			patelsort(stack);
		}
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (a->top == 1)
		{
			ft_printf("sa\n");
			st(a);
		}
		else if (a->top == 2)
			patelsort(a);
		else if (a->top > 2 && a->top < 42)
			selectsort(a, b);
		else
			stack_sort(a, b);
	}
}

/*
n = a.top + 1;
while (n > 3)
	find min
	rotate it to top and push to b
sort3(a)
push b back into a
*/
void	selectsort(t_stack *a, t_stack *b)
{
	move_until(b, a, 'b', 3);
	patelsort(a);
	while (b->top >= 0)
	{
		ft_printf("pa\n");
		pt(a, b);
	}
}

void	stack_sort(t_stack *a, t_stack *b)
{
	int				*list;
	int				i;
	unsigned int	chunksize;
	int				*indices;

	list = ft_calloc(a->top + 1, sizeof(int));
	i = -1;
	while (++i <= a->top)
		list[i] = a->data[i];
	ft_sort_int_tab(list, a->top + 1);
	chunksize = (a->top + 1) / ((91 * (a->top + 1)) / 6250 + 7);
	i = 0;
	while (a->top >= 0)
	{
		indices = find_half(a, list, chunksize, i);
		if (indices[0] == -1 && indices[1] == -1)
			i++;
		else
			move_closest(b, a, indices[0], indices[1]);
		free(indices);
	}
	move_until(a, b, 'a', 0);
}
