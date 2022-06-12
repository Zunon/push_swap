/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:53:11 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 04:05:44 by kalmheir         ###   ########.fr       */
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
		else if (stack->data[2] > stack->data[0] && stack->data[2] < stack->data[1])
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


void	swap(int *first, int *second)
{
	int third;

	third = *first;
	*first = *second;
	*second = third;
}

int		partition(int *tab, int size)
{
	int pivot;
	int current;
	int correct;

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
	int partition_index;

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
	int				min;
	int				i;
	int				minindex;
	unsigned char	dir;

	while (a->top > 2)
	{
		i = 0;
		minindex = -1;
		min = 0x7fffffff;
		while (i <= a->top)
		{
			if (a->data[i] < min)
			{
				min = a->data[i];
				minindex = i;
			}
			i++;
		}
		if (a->top - minindex < (a->top + 1) / 2)
			i = a->top - minindex;
		else
			i = minindex + 1;
		dir = (i != (minindex + 1));
		while (i--)
		{
			if (!dir)
				ft_printf("r");
			ft_printf("ra\n");
			rt(dir, a);
		}
		ft_printf("pb\n");
		pt(b, a);
	}
	patelsort(a);
	while (b->top >= 0)
	{
		ft_printf("pa\n");
		pt(a, b);
	}
}

int	*tabint(int *list, int num, int n)
{
	for(int i = 0; i < n; i++)
	{
		if (list[i] == num)
			return (list + i);
	}
	return 0;
}

void	stack_sort(t_stack *a, t_stack *b)
{
	int *list = ft_calloc(a->top + 1, sizeof(int));
	for (int i = 0; i <= a->top; i++)
		list[i] = a->data[i];
	ft_sort_int_tab(list, a->top + 1);
	int chunks = (91 * (a->top + 1))/6250 + 7;
	unsigned int chunksize = (a->top + 1)/chunks;
	int dh;
	int dl;
	int i = 0;
	while (a->top >= 0)
	{
		int high = -1;
		int low = -1;
		for (int j = a->top; j >= (a->top)/2; j--)
			if (tabint(list + (i*chunksize), a->data[j], chunksize))
			{
				high = j;
				break;
			}
		for (int j = 0; j <= (a->top)/2; j++)
			if (tabint(list + i*chunksize, a->data[j], chunksize))
			{
				low = j;
				break;
			}
		dh = a->top - high;
		dl = low + 1;
		if (high != -1 && low != -1)
		{
			if (dh <= dl)
			{
				while (dh > 0)
				{
					ft_printf("ra\n");
					rt(1, a);
					dh--;
				}
			}
			else
			{
				while(dl > 0)
				{
					ft_printf("rra\n");
					rt(0, a);
					dl--;
				}
			}
			ft_printf("pb\n");
			pt(b, a);
		}
		else if (high != -1 && low == -1)
		{
			while(dh > 0)
			{
				ft_printf("ra\n");
				rt(1, a);
				dh--;
			}
			ft_printf("pb\n");
			pt(b, a);
		}
		else if (high == -1 && low != -1)
		{
			while(dl > 0)
			{
				ft_printf("rra\n");
				rt(0, a);
				dl--;
			}
			ft_printf("pb\n");
			pt(b, a);
		}
		else if (high == -1 && low == -1)
			i++;
	}
	if (a->top == 0)
	{
		ft_printf("pb\n");
		pt(b, a);
	}
	int maxindex;
	int max;
	unsigned char dir;
	while (b->top >= 0)
	{
		i = 0;
		maxindex = -1;
		max = 0x80000000;
		while (i <= b->top)
		{
			if (b->data[i] > max)
			{
				max = b->data[i];
				maxindex = i;
			}
			i++;
		}
		if (b->top - maxindex < (b->top + 1) / 2)
			i = b->top - maxindex;
		else
			i = maxindex + 1;
		dir = (i != (maxindex + 1));
		while (i--)
		{
			if (!dir)
				ft_printf("r");
			ft_printf("rb\n");
			rt(dir, b);
		}
		ft_printf("pa\n");
		pt(a, b);
	}
}
