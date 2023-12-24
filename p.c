/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:48:25 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/12 12:15:54 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// si // a la fin alors c est uniquement pour le test
// void	mainp(va_list ptr) vrai fonction
void	noname(int i, char *tab);

int	mainp(va_list ptr)
{
	t_l				test;
	void			*p;
	unsigned long	p1;
	char			*str2;
	char			tab[30];

	p = va_arg(ptr, void *);
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p1 = (unsigned long )p;
	str2 = "0123456789abcdef";
	test.i = 0;
	while (p1 != 0)
	{
		test.x = p1 % 16;
		tab[test.i] = str2[test.x];
		p1 /= 16;
		test.i++;
	}
	test.i2 = test.i + 2;
	noname(test.i, tab);
	return (test.i2);
}

void	noname(int i, char *tab)
{
	write(1, "0x", 2);
	while (i--)
		write(1, &tab[i], 1);
}
// int	main(void)
// {
// 	char *p;
// 	int d = ft_printf("i", p);
// 	int v= printf("%p", p);
// 	printf("%d faux %d vrai", d,v);
// }