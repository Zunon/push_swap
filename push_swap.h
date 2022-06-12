/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:04:44 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 00:37:51 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	int		top;
	int		*data;
}	t_stack;

void			rt(unsigned char direction, t_stack *stack);
void			st(t_stack *stack);
void			pt(t_stack *dest, t_stack *from);
void			rr(unsigned char direction, t_stack *a, t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			int_swap(int *a, int *b);
void			patelsort(t_stack *stack);
unsigned char	is_sorted(t_stack *stack);
void			sort(t_stack *a, t_stack *b);
void			stack_sort(t_stack *a, t_stack *b);
void			selectsort(t_stack *a, t_stack *b);

#endif
