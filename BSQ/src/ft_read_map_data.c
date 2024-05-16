/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:03:38 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/15 18:03:40 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ.h"

void	allocate_map_rows(t_Map *map)
{
	map->data = malloc(map->lines * sizeof(char *));
	if (!map->data)
	{
		print_error(2);
		exit(EXIT_FAILURE);
	}
}

void	check_and_store_char(t_Map *map, char ch, int row, int column)
{
	if (ch == map->empty || ch == map->obstacle || ch == map->full)
	{
		map->data[row][column] = ch;
	}
	else
	{
		print_error(5);
		ft_putchar(ch);
		ft_putstr("\n");
		exit(EXIT_FAILURE);
	}
}

void	read_map_row(int fd, t_Map *map, int row)
{
	char	ch;
	int		column;

	column = 0;
	map->data[row] = malloc((map->lines + 1) * sizeof(char));
	if (!map->data[row])
	{
		print_error(2);
		exit(EXIT_FAILURE);
	}
	while (read(fd, &ch, 1) && ch != '\n')
	{
		if (column >= map->lines)
		{
			print_error(3);
			exit(EXIT_FAILURE);
		}
		check_and_store_char(map, ch, row, column);
		column++;
	}
	map->data[row][column] = '\0';
}

void	read_map_data(int fd, t_Map *map)
{
	int	i;

	i = 0;
	allocate_map_rows(map);
	while (i < map->lines)
	{
		read_map_row(fd, map, i);
		i++;
	}
}
