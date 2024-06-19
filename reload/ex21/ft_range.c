/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:42:08 by zqiu              #+#    #+#             */
/*   Updated: 2024/06/11 16:42:35 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
		return (NULL);
	else
	{
		ptr = malloc((max - min) * sizeof(int));
		i = 0;
		while (min < max)
			ptr[i++] = min++;
	}
	return (ptr);
}
