/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:53:11 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/11 22:04:19 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sort3(t_stack stack)
{
	if (stack.top == 2)
	{
		if (is_sorted(stack))
			return ;
		if (stack.data[0] > stack.data[1] && stack.data[0] < stack.data[2])
		{
			ft_printf("ra\n");
			rt(1, stack);
		}
		else if (stack.data[2] > stack.data[0] && stack.data[2] < stack.data[1])
		{
			ft_printf("rra\n");
			rt(0, stack);
		}
		else
		{
			ft_printf("sa\n");
			st(stack);
			sort3(stack);
		}
	}
}

unsigned char	is_sorted(t_stack stack)
{
	int	i;

	if (stack.top >= 1)
	{
		i = 0;
		while (i < stack.top)
		{
			if (stack.data[i] < stack.data[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

void	sort(t_stack a, t_stack b)
{
	if (!is_sorted(a))
	{
		if (a.top == 1)
			st(a);
		else if (a.top == 2)
			sort3(a);
		else
			stack_sort(a, b);
	}
}

void	stack_sort(t_stack a, t_stack b)
{

}
