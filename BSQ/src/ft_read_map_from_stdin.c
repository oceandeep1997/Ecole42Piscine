/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_from_stdin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:06:26 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/15 14:06:29 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ.h"

t_Map* create_map(int lines, char empty, char obstacle, char full, char** data) 
{
    t_Map *map = malloc(sizeof(t_Map));
    if (!map) 
	{
        ft_putstr("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    map->lines = lines;
    map->empty = empty;
    map->obstacle = obstacle;
    map->full = full;
    map->data = data;
    return map;
}	

char** read_map_data_from_stdin(int lines, char empty, char obstacle, char full) 
{
    char **data = malloc(lines * sizeof(char*));
    if (!data) 
	{
        ft_putstr("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    char ch;
    int i = 0;
    while (i < lines) 
	{
        data[i] = malloc((lines + 1) * sizeof(char));
        if (!data[i]) {
            ft_putstr("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        int j = 0;
        while (read(STDIN_FILENO, &ch, 1) && ch != '\n') 
		{
            if (j >= lines) {
                ft_putstr("Error reading map data");
                exit(EXIT_FAILURE);
            }
            if (ch == empty || ch == obstacle || ch == full) 
			{
                data[i][j] = ch;
                j++;
            }
        }
        i++;
    }
    return data;
}

t_Map* read_map_from_stdin() 
{
    char param_buf[100];
    int param_count = 0;
    char ch;
    while (read(STDIN_FILENO, &ch, 1) && ch != '\n' && param_count < 100) 
	{
        param_buf[param_count] = ch;
        param_count++;
    }
    param_buf[param_count] = '\0';

    int digits = 0;
    while (param_buf[digits] >= '0' && param_buf[digits] <= '9') 
	{
        digits++;
    }
    int lines = 0;
    int i = 0;
    while (i < digits) 
	{
        lines = lines * 10 + (param_buf[i] - '0');
        i++;
    }
    char empty = param_buf[digits];
    char obstacle = param_buf[digits + 1];
    char full = param_buf[digits + 2];

    return create_map(lines, empty, obstacle, full, read_map_data_from_stdin(lines, empty, obstacle, full));
}


