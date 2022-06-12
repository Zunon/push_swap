/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:37:13 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 16:15:57 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

unsigned char	return_no(char **rep)
{
	free(*rep);
	return (0);
}
