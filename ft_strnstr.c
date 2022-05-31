/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:07:17 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/06 13:58:22 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	m;
	long long int startpos;

	if (!*haystack && !*needle)
		return ((char *)haystack);
	else if (!*haystack)
		return (0);
	else if (!*needle || needle == haystack)
		return ((char *)haystack);
	n = 0;
	m = 0;
	startpos = -1;
	while ((n < len) && needle[m] && haystack[n])
	{
		if (haystack[n] == needle[m])
		{
			m++;
			if (startpos == -1)
				startpos = n;
		}
		else if (m)
		{
			m = 0;
			n = startpos;
			startpos = -1;
		}
		n++;
	}
	if (!needle[m])
		return ((char *)(haystack + n - ft_strlen(needle)));
	return (0);
}
