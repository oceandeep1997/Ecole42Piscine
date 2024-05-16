/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:53:35 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/14 17:53:40 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ.h"
#include <stdio.h>
#include <stdlib.h>

void	stdin_init(t_Map *map)
{
	find_largest_square(map);
	ft_putstr("\n");
	print_map(map);
	free(map->data);
	free(map);
}

void	input_init(t_Map *map)
{
	int		j;

	j = 0;
	find_largest_square(map);
	print_map(map);
	while (j < map->lines)
	{
		free(map->data[j]);
		j++;
	}
	free(map->data);
	free(map);
}

int	main(int argc, char **argv)
{
	int		i;
	t_Map	*map;

	i = 0;
	if (argc < 2)
	{
		map = read_map_from_stdin();
		stdin_init(map);
	}
	while (i < argc)
	{
		map = read_map(argv[i]);
		input_init(map);
		i++;
	}
	return (EXIT_SUCCESS);
}
