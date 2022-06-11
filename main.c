/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:57:21 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/11 22:04:47 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned char	check_args(int argc, char **argv, int *arr)
{
	int		i;
	int		j;
	int		n;
	char	*rep;

	i = 0;
	while (i < (argc - 1))
	{
		n = ft_atoi(argv[1 + i]);
		rep = ft_itoa(n);
		if (ft_strncmp(rep, argv[1 + i], ft_strlen(argv[1 + i])))
			return (0);
		j = 0;
		while (j < i)
		{
			if (arr[j] == n)
				return (0);
			j++;
		}
		arr[i] = n;
		i++;
	}
	return (1);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	*holder;
	int	counter;

	counter = 0;
	holder = ft_calloc(size, sizeof(int));
	if (!holder)
		return ;
	while (size > 0)
		holder[--size] = tab[counter++];
	while (--counter >= 0)
		tab[counter] = holder[counter];
	free(holder);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	i = 0;
	a.data = ft_calloc(argc - 1, sizeof(int));
	b.data = ft_calloc(argc - 1, sizeof(int));
	a.top = -1;
	b.top = -1;
	if (!a.data || !b.data)
		return (0);
	if (argc >= 2 && check_args(argc, argv, a.data))
	{
		ft_rev_int_tab(a.data, argc - 1);
		a.top = argc - 2;
		sort(a, b);
	}
	else if (argc >= 2)
	{
		write(STDERR_FILENO, "Error\n", 7);
	}
	free(a.data);
	free(b.data);
	return (0);
}
