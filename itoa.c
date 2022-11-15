/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:19:35 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/15 19:32:45 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int n)
{
	long	l;
	int		len;
	char	*s;

	l = n;
	n /= 10;
	len = 1 + (n < 0);
	while (n && ++len)
		n /= 10;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = 0;
	s[0] = '-';
	while (len > (l < 0))
	{
		s[--len + (l < 0)] = l % 10 * (1 - 2 * (l < 0)) + '0';
		l /= 10;
	}
	return (s);
}

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s\n", ft_itoa(atoi(argv[1])));
}
