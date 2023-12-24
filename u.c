/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:35:06 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/12 12:43:14 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr2(unsigned int nb);

int	mainu(va_list ptr)
{
	unsigned int	nbr;
	int				nbr2;

	nbr = va_arg(ptr, unsigned int);
	nbr2 = ft_putnbr2(nbr);
	return (nbr2);
}

int	durex1(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

int	ft_putnbr2(unsigned int nb)
{
	char				i[20];
	unsigned int		ind;
	unsigned int		nbr;
	unsigned int		test;

	test = durex1(nb);
	if (test == 1)
		return (test);
	ind = 0;
	while (nb > 0)
	{
		i[ind++] = '0' + nb % 10;
		nb = nb / 10;
	}
	nbr = ind;
	while (ind != 0)
		write(1, &i[--ind], 1);
	return (nbr);
}
