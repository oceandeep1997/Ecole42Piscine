/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:46:33 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/09 17:55:57 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	p;

	p = 1;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (power > 0)
	{
		p *= nb;
		power--;
	}
	return (p);
}
/*
int	main(void)
{
	int	i;

	i = ft_iterative_power(2, 3);
	printf("2 to the power of 3: %d", i);
}*/
