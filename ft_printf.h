/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:46:07 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/15 18:02:31 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

//+ n#0-
#define SPACE    0b1
#define PLUS     0b10
#define NEGATIVE 0b100
#define HASHTAG  0b1000
#define MINUS    0b10000


typedef struct s_printf {
	int					count;
	
	char				type;
	int					flag;
	int					fields;
	int					precision;
	int					i_base;

	unsigned long long	n;
	int					len_var;
}				t_printf;

int		ft_printf(const char *str, ...);

void	var(const char **str, va_list v, t_printf *s);

#endif
