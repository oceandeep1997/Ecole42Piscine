/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:36:29 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/14 11:36:32 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	len;

	len = -1;
	while (base[++len])
		if (base[len] == '+' || base[len] == '-' || base[len] == ' '
			|| find_double(base)
			|| (base[len] >= 9 && base[len] <= 13))
			return (0);
	return (len);
}

int	get_nbr_size(long number, char *base, int len, int size)
{
	if (number < 0)
	{
		size++;
		number = -number;
	}
	if (number >= len)
	{
		size++;
		return (get_nbr_size(number / len, base, len, size));
	}
	else
		return (size + 1);
}
