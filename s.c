/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:44:20 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/12 11:54:10 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		i = 6;
		return (i);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	mains(va_list ptr)
{
	char	*str;
	int		nbr;

	str = va_arg(ptr, char *);
	nbr = ft_putstr_fd(str);
	return (nbr);
}
// int main()
// {
// 	ft_putstr_fd("", 1);
// }