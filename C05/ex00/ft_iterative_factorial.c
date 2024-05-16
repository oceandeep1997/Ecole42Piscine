/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:38 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/09 17:26:03 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	product;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	product = 1;
	while (nb > 1)
	{
		product *= nb;
		nb--;
	}
	return (product);
}
