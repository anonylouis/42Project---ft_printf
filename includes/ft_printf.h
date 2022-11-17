/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:46:07 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/17 02:39:42 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define NULL_POINTER "(nil)"
# define NULL_STRING "(null)"

# define SPACE    0b1
# define PLUS     0b10
# define NEGATIVE 0b100
# define HASHTAG  0b1000
# define MINUS    0b10000
# define ZEROS	 0b100000

typedef struct s_printf {
	int					count;
	char				type;
	int					flag;
	long				fields;
	int					pre;
	int					pre_save;
	int					i_base;
	unsigned long long	n;
	char				*s;
	char				c[2];
	void				*content;
	int					len_var;
}				t_printf;

void	print_var(t_printf *s);

#endif
