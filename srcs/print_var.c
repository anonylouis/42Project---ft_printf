/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:30:45 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/17 02:36:58 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_var(unsigned long long n, t_printf *s)
{
	if (s->type == 99 || s->type == 115)
	{
		s->count += write(1, s->s, (s->pre == -1 || (s->pre > 0
						&& s->len_var / s->pre == 0)) * s->len_var
				+ (s->pre > 0 && !(s->len_var / s->pre == 0)) * s->pre);
		return ;
	}
	if (s->pre_save == 0 && s->n == 0)
		return ;
	if (n >= (long long unsigned)(((int [3]){16, 16, 10})[s->i_base]))
		write_var(n / (((int [3]){16, 16, 10})[s->i_base]), s);
	s->count += write(1,
			((char *[3]){"0123456789abcdef", "0123456789ABCDEF", "0123456789"})
		[s->i_base] + n % (((int [3]){16, 16, 10})[s->i_base]), 1);
}

int	len_var(unsigned long long n, char *str, t_printf *s)
{
	if (s->type == 115)
		return (str && *str && ++s->len_var && len_var(n, ++str, s));
	s->len_var = (s->type == 99 || !(s->pre_save == 0 && s->n == 0));
	while (n / (((int [3]){16, 16, 10})[s->i_base]) != 0)
		n /= (s->len_var++, (((int [3]){16, 16, 10})[s->i_base]));
	return (0);
}

void	print_var(t_printf *s)
{
	s->fields -= (len_var(s->n, s->s, s), ((s->flag & 0b111) > 0)
			+ 2 * (s->type == 112 || ((s->flag & HASHTAG) > 0)));
	if (s->type == 115 || s->type == 99)
		s->fields -= (s->pre == -1 || (s->pre > 0 && s->len_var / s->pre == 0))
			* s->len_var + (s->pre > 0 && !(s->len_var / s->pre == 0)) * s->pre;
	else
		s->fields -= (s->pre > 0 && !(s->len_var / s->pre)) * s->pre
			+ (s->pre < 1 || (s->pre > 0 && s->len_var / s->pre)) * s->len_var;
	while (!(s->flag & 16) && (!(s->flag & 32)
			|| s->pre > 0) && (s->fields)-- > 0)
		s->count += write(1, " ", 1);
	if ((s->flag & HASHTAG && s->n) || s->type == 112)
		s->count += write(1, ((char *[2]){"0x", "0X"})[s->type == 'X'], 2);
	else if (s->flag & 0b111)
		s->count += write(1, ((char *[3]){" ", "+", "-"})
			[2 * ((s->flag & NEGATIVE) > 0) + 1 * (s->flag & PLUS
					&& !(s->flag & NEGATIVE))], 1);
	while ((s->flag & 48) == 32 && s->pre == -1 && (s->fields)-- > 0)
		s->count += write(1, "0", 1);
	while (s->type != 115 && s->type != 99 && (s->pre)-- > s->len_var)
		s->count += write(1, "0", 1);
	write_var(s->n, s);
	while ((s->fields)-- > 0)
		s->count += write(1, " ", 1);
}
