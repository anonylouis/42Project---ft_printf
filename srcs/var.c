/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:54:30 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/16 22:08:48 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag(const char **str, t_printf *s)
{
	if (**str != 99 && **str != 115 && **str != 112 && **str != 100
		&& **str != 88 && **str != 105 && **str != 117 && **str != 120 && **str)
	{
		if (**str == 32)
			s->flag += SPACE;
		if (**str == 43)
			s->flag += PLUS;
		if (**str == 35)
			s->flag += HASHTAG;
		if (**str == 45)
			s->flag += MINUS;
		if (s->precision == -1 && s->fields == 0 && **str == 48)
			s->flag += ZEROS;
		else if (s->precision == -1 && **str > 47 && **str < 58)
			s->fields = 10 * s->fields + **str - 48;
		else if (**str > 47 && **str < 58)
			s->precision = 10 * s->precision + **str - 48;
		if (**str == 46)
			s->precision = 0;
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
	/*printf("DEBUG : s = %s\n", *str);
	printf("DEBUG : type = %c(%d)\n", s->type, s->type);
	printf("DEBUG : flag = %d\n", s->flag);
	printf("DEBUG : fields = %ld\n", s->fields);
	printf("DEBUG : precision = %d\n", s->precision);
	printf("DEBUG : i_base = %d\n", s->i_base);*/

	// recup l arugment dans va_arg
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

	/*if (s->type == 's')
		printf("DEBUG : s_content = %s\n", s->s);
	else
		printf("DEBUG : n_content = %llu\n", s->n);*/
	if (s->type == 112 && s->n == 0)
	{
		s->type = 115;
		s->s = NULL_POINTER;
	}
	if (s->type == 115 && !(s->s) && s->precision >= 6)
		s->s = NULL_STRING;

	print_var(s);

}
