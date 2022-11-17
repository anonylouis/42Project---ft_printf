/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:45:13 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/17 02:36:55 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag(const char **str, t_printf *s)
{
	if (**str != 99 && **str != 115 && **str != 112 && **str != 100
		&& **str != 88 && **str != 105 && **str != 117 && **str != 120 && **str)
	{
		if (**str == 32 && !(s->flag & SPACE))
			s->flag += SPACE;
		if (**str == 43 && !(s->flag & PLUS))
			s->flag += PLUS;
		if (**str == 35 && !(s->flag & HASHTAG))
			s->flag += HASHTAG;
		if (**str == 45 && !(s->flag & MINUS))
			s->flag += MINUS;
		if (s->pre < 0 && s->fields < 1 && **str == 48 && !(s->flag & 32))
			s->flag += ZEROS;
		else if (s->pre == -1 && **str > 47 && **str < 58)
			s->fields = 10 * s->fields + **str - 48;
		else if (**str > 47 && **str < 58)
			s->pre = 10 * s->pre + **str - 48;
		if (**str == 46)
			s->pre = 0;
		return (flag((++(*str), str), s));
	}
	s->type = **str;
	if (**str == 120 || **str == 88 || **str == 112)
		s->i_base = **str == 88;
}

long	flag_negative(va_list v, t_printf *s)
{
	long	n;

	n = va_arg(v, int);
	s->flag += NEGATIVE * (n < 0);
	return (n * (1 - 2 * (n < 0)));
}

void	var(const char **str, va_list v, t_printf *s)
{
	(flag(str, s), (*str)++);
	if (s->type == 100 || s->type == 105)
		s->n = flag_negative(v, s);
	else if (s->type == 88 || s->type == 117 || s->type == 120)
		s->n = va_arg(v, unsigned int);
	else if (s->type == 99)
		s->c[0] = (char) va_arg(v, int);
	else if (s->type == 115)
		s->s = va_arg(v, char *);
	else
		s->n = (unsigned long long) va_arg(v, void *);
	if (s->type == 112 && s->n == 0)
	{
		s->type = 115;
		s->s = NULL_POINTER;
	}
	if (s->type == 115 && !(s->s) && (s->pre == -1 || s->pre >= 6))
		s->s = NULL_STRING;
	s->pre_save = s->pre;
	print_var(s);
}

int	reset_s(t_printf *s)
{
	s->i_base = 2;
	s->flag = 0;
	s->pre = -1;
	s->fields = 0;
	s->c[1] = 0;
	s->s = s->c;
	s->n = 0;
	s->len_var = 0;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list		v;
	t_printf	s;

	s.count = 0;
	va_start(v, str);
	while (*str)
	{
		if (*str == 37 && (++str, 1) && *str != 37 && reset_s(&s))
			var(&str, v, &s);
		else
			s.count += write(1, str++, 1);
	}
	va_end(v);
	return (s.count);
}
