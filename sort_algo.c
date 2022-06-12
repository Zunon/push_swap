/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:15:30 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 17:10:10 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * patelsort(stack)
 * --------------------
 * sorts a stack given that it has exactly 3 elements
 *
 * parameters:
 *  stack: stack to be sorted
 *
 * note:
 *  this algorithm was constructed be considering the sample space as a graph,
 *  where each state of the stack is a node and the edges are the operations
 *  connecting them. Then we've used dijkstra's algorithm to compute the most
 *  optimum paths to the solved state.
 *  as the algorithms' namesake likes to code, this function is mostly if
 *  statements to check for the specific state of the stack, and use operations
 *  tailored to that state to reach the solved state. hence mpatel or patelsort.
 */
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

/*
 * sort(stack a, stack b)
 * --------------------
 * selects a sorting algorithm and applies it based on the problem size derived
 * from stack a.
 *
 * parameters:
 *  stack a: the array in which all values initially exist unsorted
 *  stack b: an empty stack to aid in our sorting
 */
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
 * selectsort(stack a, stack b)
 * --------------------
 * sorts the numbers in stack a, by taking the smallest number in stack a to
 * stack b, and repeating until there's only 3 numbers remaining in stack a,
 * after which it applies patelsort to stack a, and pushes all numbers from
 * stack b to a (which were effectively selection sorted in the process of
 * pushing them to stack b).
 *
 * parameters:
 *  stack a: the stack in which numbers start from and need to be sorted to
 *  stack b: the stack that starts empty
 *
 * pseudocode:
 *	n = a.top + 1;
 *	while (n > 3)
 *		find min
 *		rotate it to top and push to b
 *	patelsort(a)
 *	push b back into a
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

/*
 * stack_sort(stack a, stack b)
 * --------------------
 * sorts the numbers into stack a by moving the numbers in value-based chunks,
 * this ensures that when we're pushing back to b, the values we're looking for
 * are close to each other, with the help of rb and rrb, this makes putting the
 * numbers back in a sorted way faster (for bigger problem sizes).
 *
 * parameters:
 *  stack a: the stack in which numbers start from and need to be sorted to
 *  stack b: the stack that starts empty
*/
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
	free(list);
	move_until(a, b, 'a', 0);
}
