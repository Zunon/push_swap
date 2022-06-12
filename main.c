/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:57:21 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/12 16:15:13 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned char	check_args(int argc, char **argv, int *arr)
{
	int		nums[3];
	char	*rep;

	nums[0] = -1;
	while (++(nums[0]) < (argc))
	{
		nums[2] = ft_atoi(argv[nums[0]]);
		rep = ft_itoa(nums[2]);
		if (ft_strncmp(rep, argv[nums[0]], ft_strlen(argv[nums[0]])))
			return (return_no(&rep));
		nums[1] = -1;
		while (++(nums[1]) < nums[0])
			if (arr[nums[1]] == nums[2])
				return (return_no(&rep));
		arr[nums[0]] = nums[2];
		free(rep);
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
	t_stack	a;
	t_stack	b;

	b.top = -1;
	refactor_args(&argc, &argv);
	a.data = ft_calloc(argc, sizeof(int));
	b.data = ft_calloc(argc, sizeof(int));
	if (!a.data || !b.data)
		return (0);
	if (argc >= 1 && check_args(argc, argv, a.data))
	{
		ft_rev_int_tab(a.data, argc);
		a.top = argc - 1;
		sort(&a, &b);
	}
	else if (argc >= 1)
		write(STDERR_FILENO, "Error\n", 7);
	free_my_data(&a, &b, &argv);
	return (0);
}
