/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriera-c <nriera-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:08 by nriera-c          #+#    #+#             */
/*   Updated: 2024/05/15 15:18:10 by nriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ.h"

void	print_map(const t_Map *map)
{
	int	i;

	i = 0;
	while (i < map->lines)
	{
		ft_putstr(map->data[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}
