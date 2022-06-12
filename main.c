/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:57:21 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 13:52:48 by kalmheir         ###   ########.fr       */
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
	while (i < (argc))
	{
		n = ft_atoi(argv[i]);
		rep = ft_itoa(n);
		if (ft_strncmp(rep, argv[i], ft_strlen(argv[i])))
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

char	*ft_strjoinsp(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (0);
	result[0] = 0;
	ft_strlcat(result, s1, len1 + len2 + 2);
	ft_strlcat(result, " ", len1 + len2 + 2);
	ft_strlcat(result, s2, len1 + len2 + 2);
	return (result);
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
	b.top = -1;
	if (!a.data || !b.data)
		return (0);
	refactor_args(&argc, &argv);
	if (argc >= 1 && check_args(argc, argv, a.data))
	{
		ft_rev_int_tab(a.data, argc);
		a.top = argc - 1;
		sort(&a, &b);
	}
	else if (argc >= 1)
		write(STDERR_FILENO, "Error\n", 7);
	free(a.data);
	free(b.data);
	return (0);
}
