/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:45:13 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/16 16:58:13 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	reset_s(t_printf *s)
{
	s->i_base = 2;
	s->flag = 0;
	s->precision = -1; // foutre a 0 des qu on a un point, puis atoi a chaque int 
	s->fields = 0;
	s->c[1] = 0;
	s->s = s->c;
	s->n = 0;
	s->len_var = 0;
	return (1);
}

int		ft_printf(const char *str, ...)
{
	va_list		v;
	t_printf	s;

	s.count = 0;
	va_start(v, str);
	while (*str)
	{
		if (*str == 37 && (++str,1) && *str != 37 && reset_s(&s) )
			var(&str, v, &s);
		else
			s.count += write(1, str++, 1);
	}
	va_end(v);
	return (s.count);
}
