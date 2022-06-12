/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:37:13 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 17:49:02 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * move_closest(stack dest, stack src, int high, int low)
 * --------------------
 * moves the value closest to the top of the stack (in both directions) using
 * the indices given to us from find_half().
 *
 * parameters:
 *  stack dest: the stack to be pushed into
 *  stack src: the stack to be pushed from
 *  int high: the value closest to the top via rotation
 *  int low: the value closest to the top via reverse rotation
 */
void	move_closest(t_stack *dest, t_stack *src, int high, int low)
{
	if (high != -1 && low != -1)
	{
		if (src->top - high <= low + 1)
			move_to_top(src, high, 'a');
		else
			move_to_top(src, low, 'a');
		ft_printf("pb\n");
		pt(dest, src);
	}
	else if (high != -1 && low == -1)
	{
		move_to_top(src, high, 'a');
		ft_printf("pb\n");
		pt(dest, src);
	}
	else if (high == -1 && low != -1)
	{
		move_to_top(src, low, 'a');
		ft_printf("pb\n");
		pt(dest, src);
	}
}

/*
 * free_my_data(stack a, stack b, char ***)
 * --------------------
 * frees the allocated memory in the given parameters, which are the arrays
 * encapsulated by both stacks, the strings inside the string array that's
 * pointed to, and the string array itself
 *
 * parameters:
 *  stack a: stack a encapsulating an array
 *  stack b: stack b encapsulating another array
 *  char ***: a pointer to a string array of arguments to the program
 *
 * returns: a pointer to the number found inside the array (mainly used in this
 *  program for its truthiness)
 */
void	free_my_data(t_stack *a, t_stack *b, char ***argv)
{
	int	i;

	i = 0;
	free(a->data);
	free(b->data);
	while ((*argv)[i])
		free((*argv)[i++]);
	free((*argv)[i]);
	free(*argv);
}

/*
 * return_no(char **) -> bool
 * --------------------
 * frees the given string and returns 0
 *
 * parameters:
 *  char **: a pointer to the string that is to be freed.
 *
 * returns: 0
 */
unsigned char	return_no(char **rep)
{
	free(*rep);
	return (0);
}
