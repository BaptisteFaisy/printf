/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:45:53 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/12 16:06:16 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parsingvtype2(const char *str, int i, va_list ptr);
int		parsingvtype(const char *str, va_list ptr);
int		parsingvtype3(const char *str, int i, va_list ptr);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		nbr;

	va_start (ptr, str);
	nbr = parsingvtype(str, ptr);
	if (nbr == 0)
	{
		va_end(ptr);
		return (nbr);
	}
	va_end(ptr);
	return (nbr);
}

// int	parsing(char s, char c)
// {
// 	int	vreturn;

// 	vreturn = -1;
// 	if ((s == '%') && c == 'c')
// 		vreturn = 0;
// 	else if ((s == '%') && c == 's')
// 		vreturn = 1;
// 	else if ((s == '%') && c == 'p')
// 		vreturn = 2;
// 	else if ((s == '%') && c == 'd')
// 		vreturn = 3;
// 	else if ((s == '%') && c == 'i')
// 		vreturn = 4;
// 	else if ((s == '%') && c == 'u')
// 		vreturn = 5;
// 	else if ((s == '%') && c == 'x')
// 		vreturn = 6;
// 	else if ((s == '%') && c == 'X')
// 			vreturn = 7;
// 	else if ((s == '%') && c == '%')
// 			vreturn = 8;
// 	return (vreturn);
// }

int	check(const char *str, int i)
{
	if (str[i] == '%' && (str[i + 1] != 'p' && str[i + 1] != 's'
			&& str[i + 1] != 'c' && str[i + 1] != 'x' && str[i + 1] != 'X'
			&& str[i + 1] != '%' && str[i + 1] != 'd' && str[i + 1] != 'u'
			&& str[i + 1] != 'i' && str[i + 1] != 'u' && str[i + 1] != 'c'))
		return (0);
	return (1);
}

int	parsingvtype(const char *str, va_list ptr)
{
	int	i;
	int	nbr1;
	int	nbr2;

	i = 0;
	nbr1 = 0;
	while (str[i] != 0)
	{
		if (check(str, i) == 0)
			return (0);
		else
		{
			nbr2 = parsingvtype2(str, i, ptr);
			if (nbr2 == -1)
			{
				write(1, &str[i], 1);
				i--;
				nbr1++;
			}
			else
				nbr1 += nbr2;
		}
		i += 2;
	}
	return (nbr1);
}

int	parsingvtype2(const char *str, int i, va_list ptr)
{
	int	check;

	check = -1;
	if ((str[i] == '%') && str[i + 1] == 'c')
		check = mainc(ptr);
	else if ((str[i] == '%') && str[i + 1] == 's')
	{
		check = mains(ptr);
	}
	else if ((str[i] == '%') && str[i + 1] == 'p')
	{
		check = mainp(ptr);
	}
	else if ((str[i] == '%') && str[i + 1] == 'd')
	{
		check = maind(ptr);
	}
	else if ((str[i] == '%') && (str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'))
	{
		check = parsingvtype3(str, i, ptr);
	}
	return (check);
}

int	parsingvtype3(const char *str, int i, va_list ptr)
{
	int	nbr;

	if ((str[i] == '%') && (str[i + 1] == 'u'))
		nbr = mainu(ptr);
	else if ((str[i] == '%') && str[i + 1] == 'i')
		nbr = maind(ptr);
	else if ((str[i] == '%') && str[i + 1] == 'x')
		nbr = mainx(ptr);
	else if ((str[i] == '%') && str[i + 1] == 'X')
		nbr = mainxa(ptr);
	else if ((str[i] == '%') && str[i + 1] == '%')
		nbr = mainpour();
	return (nbr);
}

// int main()
// {
// 	int i = 98;
// 	ft_printf("%d", i);
// }