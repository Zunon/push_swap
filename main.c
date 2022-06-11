/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:57:21 by kalmheir          #+#    #+#             */
/*   Updated: 2022/05/31 09:06:53 by kalmheir         ###   ########.fr       */
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
	int holder[size];
	int counter;

	counter = 0;
	while (size > 0)
		holder[--size] = tab[counter++];
	while (--counter >= 0)
		tab[counter] = holder[counter];
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack A;
	t_stack B;

	i = 0;
	A.data = ft_calloc(argc - 1, sizeof(int));
	B.data = ft_calloc(argc - 1, sizeof(int));
	A.top = -1;
	B.top = -1;
	if (!A.data || !B.data)
		return (0);
	if (argc >= 2 && check_args(argc, argv, A.data))
	{
		ft_rev_int_tab(A.data, argc - 1);
		A.top = argc - 2;
	}
	else if (argc >= 2)
		write(STDERR_FILENO, "Error\n", 7);
	return (0);
}
