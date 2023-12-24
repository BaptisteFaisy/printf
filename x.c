/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:29:51 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/12 16:15:04 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// pas encore fait pour return le nombre de char print
int	ft_putnbr_base1(int nbr, char *base);

int	mainx(va_list ptr)
{
	int	nbr;
	int	nbr1;

	nbr = va_arg(ptr, int);
	nbr1 = ft_putnbr_base1(nbr, "0123456789abcdef");
	return (nbr1);
}

// long	print(long nbr)
// {
// 	long	nbr1;

// 	nbr1 = 2684354559 + nbr;
// 	return (ft_putnbr_base1(nbr, "0123456789abcdef"));
// }

long	neg(long nbr, char *base, int nbr2)
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
		write(1, "f", 1);
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
	while (i != -1)
		write(1, &tab[i--], 1);
	return (nbr2);
}

int	ft_putnbr_base1(int nbr, char *base)
{
	char	tab[35];
	int		i;
	long	nbr1;
	int		nbr2;

	nbr1 = nbr;
	i = 0;
	nbr2 = 0;
	if (nbr1 < 0)
		return (neg(nbr, base, nbr2));
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
// int main()
// {
//     int i = ft_putnbr_base1(-2147483642, "0123456789abcdef");
// 	printf(" %x \n %i", -2147483642, i);
// }
