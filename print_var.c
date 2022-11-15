/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:30:45 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/15 17:24:27 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long n, t_printf *s)
{
	if (n >= (((int [3]){16, 16, 10})[s->i_base]))
		ft_putnbr_base(n / (((int [3]){16, 16, 10})[s->i_base]), s);
	s->count += write(1,
			((char *[3]){"0123456789abdef", "0123456789ABCDEF", "0123456789"})
		[s->i_base] + n % (((int [3]){16, 16, 10})[s->i_base]), 1);
}

//for number
void	len_var(unsigned long long n, t_printf *s)
{
	s->len_var = 1 + 2 * ((s->flag & HASHTAG) > 0) + ((s->flag & 15) < 8);
	while (n / (((int [3]){16, 16, 10})[s->i_base]) != 0)
		n /= (s->len_var++, (((int [3]){16, 16, 10})[s->i_base]));
}

//for number
void	print_var(t_printf *s)
{
	len_var(s->n, s);
	printf("DEBUG : len_var = %d\n", s->len_var);
	// fields - max (precision, len_var)
	// (precision - len affiche)
	if (s->flag & HASHTAG)
		s->count += write(1, ((char *[2]){"0x", "0X"})[s->type == 'X'], 2);
	else if (s->flag & SPACE || s->flag & PLUS || s->flag & NEGATIVE)
		s->count += write(1, ((char *[3]){" ", "+", "-"})
			[3 * ((s->flag & NEGATIVE) > 0) + 2 * (s->flag & PLUS
					&& !(s->flag & NEGATIVE)) + 1 * (s->flag & 7 == 7)], 1);
	ft_putnbr_base(s->n, s);

}

//nombre :
// fields rempli de 0 si flag 0 (et pas precision) sinon espace

// fields - len_affiche (si pas de flag -)     tous
// flag # (0x ou 0X)                           si x ou X
// flag + ou ' ' ou negatif                    si d ou i
// putnbr
// fields - len affiche (si flag -)