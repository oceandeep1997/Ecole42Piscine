/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_largest_square.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:18:42 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/15 12:18:44 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/BSQ.h"

int	min(int a, int b)
{
	if (a < b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

void process_map_row(t_Map *map, int **dp, int i, int *max_size, int *max_x, int *max_y)
{
	int j = 0;
	while (j < map->lines)
	{
		if (map->data[i][j] == map->empty)
		{
			dp[i][j] = 1;
		} else {
			dp[i][j] = 0;
		}
		if (dp[i][j] && i > 0 && j > 0)
		{
			dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
		if (dp[i][j] > *max_size)
		{
			*max_size = dp[i][j];
			*max_x = j - *max_size + 1;
			*max_y = i - *max_size + 1;
		}
		j++;
	}
}

void	find_largest_square(t_Map *map)
{
	int	max_size;
	int	max_x;
	int	max_y;
	int **dp;
	int i;
	int j;

	max_size = 0;
	max_x = 0;
	max_y = 0;
	dp = malloc(map->lines * sizeof(int *));
	i = 0;
	while (i < map->lines)
	{
		dp[i] = malloc(map->lines * sizeof(int));
		process_map_row(map, dp, i, &max_size, &max_x, &max_y);
		i++;
	}
	i = max_y;
	while (i < max_y + max_size)
	{
		j = max_x;
		while (j < max_x + max_size)
		{
			map->data[i][j] = map->full;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->lines)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
