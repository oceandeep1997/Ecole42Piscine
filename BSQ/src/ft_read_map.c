/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:35:15 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/15 11:35:17 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ.h"

void	extract_parameters(t_Map *map, char *param_buf)
{
	int	digits;
	int	i;

	digits = 0;
	while (param_buf[digits] >= '0' && param_buf[digits] <= '9')
	{
		digits++;
	}
	map->lines = 0;
	i = 0;
	while (i < digits)
	{
		map->lines = map->lines * 10 + (param_buf[i] - '0');
		i++;
	}
	map->empty = param_buf[digits];
	map->obstacle = param_buf[digits + 1];
	map->full = param_buf[digits + 2];
}

void	allocate_map_data(t_Map *map)
{
	map->data = malloc(map->lines * sizeof(char *));
	if (!map->data)
	{
		print_error(2);
		exit(EXIT_FAILURE);
	}
}

t_Map	*read_map(const char *file)
{
	int		fd;
	t_Map	*map;
	char	param_buf[100];
	int		param_count;

	fd = open_file(file);
	map = allocate_map();
	param_count = 0;
	read_parameters(fd, param_buf, &param_count);
	extract_parameters(map, param_buf);
	allocate_map_data(map);
	read_map_data(fd, map);
	close(fd);
	return (map);
}
