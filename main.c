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

#include <unistd.h>

unsigned char	check_args(int argc, char **argv)
{

}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc >= 2 && check_args(argc, argv))
	{

	}
	else if (argc >= 2)
		write(STDERR_FILENO, "Error\n", 7);
	return (0);
}
