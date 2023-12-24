/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:38:46 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/12 16:16:48 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// pas encore fait pour return le nombre de char print

int	ft_putnbr_base2(int nbr, char *base);

int	mainxa(va_list ptr)
{
	int		nbr;
	int		nbr1;

	nbr = va_arg(ptr, int);
	nbr1 = ft_putnbr_base2(nbr, "0123456789ABCDEF");
	return (nbr1);
}

long	neg1(long nbr, char *base, int nbr2)
{
	long	nbr1;
	char	tab[35];
	int		i;

	if (nbr == -2147483648)
	{
		write(1, "80000000", 8);
		return (8);
	}
	else
		write(1, "F", 1);
	nbr1 = 2147483648 + nbr;
	i = 0;
	while (nbr1 >= 256)
	{
		nbr = nbr1 % 16;
		nbr1 = nbr1 / 16;
		tab[i++] = base[nbr];
	}
	tab[i] = base [(nbr1 % 16)];
	nbr2 += i + 2;
	tab[i + 1] = '\0';
	while (i != -1)
		write(1, &tab[i--], 1);
	return (nbr2);
}

int	ft_putnbr_base2(int nbr, char *base)
{
	char	tab[35];
	int		i;
	long	nbr1;
	int		nbr2;

	nbr1 = nbr;
	i = 0;
	nbr2 = 0;
	if (nbr1 < 0)
		return (neg1(nbr, base, nbr2));
	while (nbr1 >= 16)
	{
		nbr = nbr1 % 16;
		nbr1 = nbr1 / 16;
		tab[i++] = base[nbr];
	}
	tab[i] = base [(nbr1 % 16)];
	nbr2 += i + 1;
	tab[i + 1] = '\0';
	while (tab[i])
		write(1, &tab[i--], 1);
	return (nbr2);
}
