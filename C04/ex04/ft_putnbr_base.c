/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:38:07 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/09 15:43:23 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pt_char(char c)
{
	write(1, &c, 1);
}

int	find_double(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_in_base(char c, char *base)
{
	while (*base)
		if (c == *base++)
			return (1);
	return (0);
}

void	printnb(long number, char *base, int len)
{
	if (number < 0)
	{
		pt_char('-');
		number = -number;
	}
	if (number >= len)
	{
		printnb(number / len, base, len);
	}
	pt_char(base[number % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		len;
	long	number;

	i = 0;
	len = 0;
	number = nbr;
	while (base[len])
		len++;
	if (len < 2)
		return ;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return ;
		i++;
	}
	if (find_double(base))
	{
		return ;
	}
	printnb(number, base, len);
}
/*
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;

	while (str[i] == ' '  ||
		   str[i] == '\t' ||
		   str[i] == '\n' ||
		   str[i] == '\v' ||
		   str[i] == '\f' ||
		   str[i] == '\r')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int		main(int argc, char **argv)
{
	int		n;
	char	*baseSymbols;

	n = ft_atoi(argv[1]);
	baseSymbols = argv[2];

	//Exercise function
	ft_putnbr_base(n, baseSymbols);
}*/
