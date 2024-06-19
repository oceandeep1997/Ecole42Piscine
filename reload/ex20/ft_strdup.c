/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:16:43 by zqiu              #+#    #+#             */
/*   Updated: 2024/06/11 16:39:57 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		length;
	char	*dest;

	length = 0;
	while (src[length])
		length++;
	dest = (char *)malloc((length + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	length = 0;
	while (src[length])
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';
	return (dest);
}
