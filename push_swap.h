/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:04:44 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 16:15:25 by kalmheir         ###   ########.fr       */
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
void			swap(int *a, int *b);
void			patelsort(t_stack *stack);
unsigned char	is_sorted(t_stack *stack);
void			sort(t_stack *a, t_stack *b);
void			stack_sort(t_stack *a, t_stack *b);
void			selectsort(t_stack *a, t_stack *b);
unsigned int	find_extreme(t_stack *stack, unsigned char min);
void			refactor_args(int *argc, char ***argv);
void			move_to_top(t_stack *stack, unsigned int index, char name);
void			ft_sort_int_tab(int *tab, int size);
int				*tabint(int *list, int num, int n);
char			*ft_strjoinsp(char const *s1, char const *s2);
void			move_until(t_stack *dest, t_stack *src, char name,
					unsigned char until);
int				*find_half(t_stack *stack, int *list, int chunksize, int i);
void			move_closest(t_stack *dest, t_stack *src, int high, int low);
void			free_my_data(t_stack *a, t_stack *b, char ***argv);
unsigned char	return_no(char **rep);

#endif
