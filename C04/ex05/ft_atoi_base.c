/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:47:13 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/09 16:53:28 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
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

int	ft_baselen(char *base)
{
	int	size;

	size = -1;
	while (base[++size])
		if (base[size] == '+' || base[size] == '-' || base[size] == ' '
			|| find_double(base)
			|| (base[size] >= 9 && base[size] <= 13))
			return (0);
	return (size);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	sign;
	int	result;

	len = ft_baselen(base);
	sign = 1;
	result = 0;
	if (len < 2)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_in_base(*str, base) >= 0)
	{
		result = result * len + ft_in_base(*str, base);
		str++;
	}
	return (result * sign);
}
/*
int	main(int argc, char **argv)
{
	char    *base;
	char    *nbr;
	int        result;

	    //Basically i have to find the value of nbr
	    //in this example -> 42
	nbr = " -42";
	base = "0123456789";

	                    //nbr & base a are strings!
	 result = ft_atoi_base(nbr, base);

	 printf("The real value of \"%s\" in base \"%s\" is -> %d\n", 
	 nbr, base, result);
}*/
