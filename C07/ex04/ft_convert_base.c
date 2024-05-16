/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:34:36 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/14 10:34:39 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
/* #include "ft_convert_base2.c" */

int	ft_in_base(char c, char *base);
int	find_double(char *base);
int	ft_baselen(char *base);
int	get_nbr_size(long number, char *base, int len, int size);

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

char	*base_wrong(char *base)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (NULL);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (NULL);
		i++;
	}
	if (find_double(base))
	{
		return (NULL);
	}
	return (base);
}

char	*convert_base(int result, char *base, int len)
{
	int		size;
	char	*arr;

	if (result == 0)
	{
		arr = (char *)malloc(2);
		arr[0] = base[0];
		arr[1] = 0;
		return (arr);
	}
	size = get_nbr_size(result, base, len, 0);
	arr = malloc((size + 1) * sizeof(char));
	arr[size] = 0;
	if (result < 0)
	{
		result *= -1;
		arr[0] = '-';
	}
	while (result)
	{
		arr[--size] = base[result % len];
		result /= len;
	}
	return (arr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	result;
	int		len;

	if (!(base_wrong(base_from)) || !(base_wrong(base_to)))
		return (NULL);
	result = ft_atoi_base(nbr, base_from);
	len = ft_baselen(base_to);
	return (convert_base(result, base_to, len));
}
/*
int	main(int argc, char **argv)
{
	char    *base_from;
	char	*arr;
	char	*base_to;
	char	*nbr;
	int		result;

	    //Basically i have to find the value of nbr
	    //in this example -> 42
	nbr = argv[1];
	base_from = "0123456789";
	base_to = argv[2];
	                    //nbr & base a are strings!
	arr = ft_convert_base(nbr, base_from, base_to);

	printf("The convert of \"%s\" from base  \"%s\" in base \"%s\" is -> %s\n", 
	nbr,base_from, base_to, arr);
}*/