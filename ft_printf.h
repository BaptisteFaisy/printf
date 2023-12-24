/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:38:41 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/12 12:52:17 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	int				i;
	unsigned long	x;
	int				i2;
}				t_l;

int		ft_printf(const char *str, ...);
int		mainc(va_list ptr);
int		maini(va_list ptr);
int		mainp(va_list ptr);
int		mains(va_list ptr);
int		mainu(va_list ptr);
int		mainx(va_list ptr);
int		mainxa(va_list ptr);
int		maind(va_list ptr);
int		mainpour(void);

#endif