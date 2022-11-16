/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:30:45 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/16 22:02:54 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long n, t_printf *s)
{
	if (s->type == 99 || s->type == 115)
	{
		// pas de precison --> la len
		// sinon min(len, precision)
		//printf("DEBUG : len_var = %d\n", s->len_var);
		//printf("DEBUG : precision = %d\n", s->precision);
		//printf("DEVUG : len = %d\n", (s->precision == -1 || (s->precision > 0 &&  s->len_var / s->precision == 0))  * s->len_var + (s->precision > 0 &&  !(s->len_var / s->precision == 0)) * s->precision);
		s->count += write(1, s->s, (s->precision == -1 || (s->precision > 0 &&  s->len_var / s->precision == 0))  * s->len_var + (s->precision > 0 &&  !(s->len_var / s->precision == 0)) * s->precision);
		return ;
	}
	if (s->precision == 0 && s->n == 0)
		return ;
	if (n >= (((int [3]){16, 16, 10})[s->i_base]))
		ft_putnbr_base(n / (((int [3]){16, 16, 10})[s->i_base]), s);
	s->count += write(1,
			((char *[3]){"0123456789abcdef", "0123456789ABCDEF", "0123456789"})
		[s->i_base] + n % (((int [3]){16, 16, 10})[s->i_base]), 1);
}

int		len_var(unsigned long long n, char *str, t_printf *s)
{
	if (s->type == 99 || s->type == 115)
		return (str && *str && ++s->len_var && len_var(n, ++str, s));
	s->len_var = 1;
	while (n / (((int [3]){16, 16, 10})[s->i_base]) != 0)
		n /= (s->len_var++, (((int [3]){16, 16, 10})[s->i_base]));
}

//for number
void	print_var(t_printf *s)
{

	//printf("\nn = %llu\n", s->n);
	s->fields -= (len_var(s->n, s->s, s), ((s->flag & 0b111) > 0) + 2 * (s->type == 112 || ((s->flag & HASHTAG) > 0)));
	// printf("DEBUG : len_var = %d\n", s->len_var);
	
	// printf("DEBUG : fields = %ld\n", s->fields);
	// printf("DEBUG : precision = %d\n", s->precision);
	//pour des string : on enleve min (len_var, precision), si y'a une precision ! pas de precision = on enelve len_var
	if (s->type == 115 || s->type == 99)
		s->fields -= (s->precision == -1 || (s->precision > 0 &&  s->len_var / s->precision == 0)) * s->len_var + (s->precision > 0 &&  !(s->len_var / s->precision == 0)) * s->precision;
	else
		s->fields -= (s->precision > 0 &&  s->len_var / s->precision == 0) * s->precision + (s->precision < 1 || (s->precision > 0 &&  !(s->len_var / s->precision == 0))) * s->len_var;
	
	// printf("DEBUG : fields = %ld\n", s->fields);
	// printf("DEBUG : precision = %d\n", s->precision);
	while (!(s->flag & 0b110000) && (s->fields)-- > 0)
		s->count += write(1, " ", 1);
	if (s->flag & HASHTAG || s->type == 112)
		s->count += write(1, ((char *[2]){"0x", "0X"})[s->type == 'X'], 2);
	else if (s->flag & 0b111)
		s->count += write(1, ((char *[3]){" ", "+", "-"})
			[2 * ((s->flag & NEGATIVE) > 0) + 1 * (s->flag & PLUS
					&& !(s->flag & NEGATIVE))], 1);
	while ((s->flag & 0b110000) == ZEROS && (s->fields)-- > 0)
		s->count += write(1, "0", 1);
	//printf("DEBUG : precision = %d\n", s->precision);
	while (s->type != 115 && s->type != 99 && s->precision-- > s->len_var)
		s->count += write(1, "0", 1);
	ft_putnbr_base(s->n, s);
	while ((s->fields)-- > 0)
		s->count += write(1, " ", 1);
}

//nombre :
// fields rempli de 0 si flag 0 (et pas precision) sinon espace

// fields - len_affiche (si pas de flag -)     tous
// flag # (0x ou 0X)                           si x ou X
// flag + ou ' ' ou negatif                    si d ou i
// putnbr
// fields - len affiche (si flag -)