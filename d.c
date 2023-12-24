/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:37:23 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/13 10:41:56 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr1(int n);

int	maind(va_list ptr)
{
	int	nbr;
	int	nbr2;

	nbr = va_arg(ptr, int);
	nbr2 = ft_putnbr1(nbr);
	return (nbr2);
}

void	ft_putchar_fd1(char c, int fd)
{
	write(fd, &c, 1);
}

int	durex(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	return (0);
}

int	little(int p, int nbr)
{
	if (p < 0)
	{
		write(1, "-", 1);
		nbr++;
	}
	return (nbr);
}

int	ft_putnbr1(int nb)
{
	char	i[20];
	int		ind;
	int		p;
	int		nbr;
	int		test;

	test = durex(nb);
	if (test == 1 || test == 11)
		return (test);
	p = nb;
	ind = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb > 0)
	{
		i[ind++] = '0' + nb % 10;
		nb = nb / 10;
	}
	nbr = ind;
	nbr = little(p, nbr);
	while (ind != 0)
		write(1, &i[--ind], 1);
	return (nbr);
}
