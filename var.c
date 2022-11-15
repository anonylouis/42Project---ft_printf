/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:54:30 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/15 18:23:50 by lcalvie          ###   ########.fr       */
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
		if (s->precision == -1 && **str > 47 && **str < 58)
			s->fields += 10 * s->fields + **str - 48;
		else if (**str > 47 && **str < 58)
			s->precision += 10 * s->precision + **str - 48;
		if (**str == 46)
			s->precision = 0;
		return (flag((++(*str), str), s));
	}
	s->type = **str;
	if (**str == 120 || **str == 88 || **str == 112)
		s->i_base = **str == 88;
}

void	var(const char **str, va_list v, t_printf *s)
{
	(flag(str, s), (*str)++);
	
	/*printf("DEBUG : s = %s\n", *str);
	printf("DEBUG : type = %c(%d)\n", s->type, s->type);
	printf("DEBUG : flag = %d\n", s->flag);
	printf("DEBUG : fields = %d\n", s->fields);
	printf("DEBUG : precision = %d\n", s->precision);
	printf("DEBUG : i_base = %d\n", s->i_base);*/
}
