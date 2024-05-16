/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqiu <zqiu@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:13:08 by zqiu              #+#    #+#             */
/*   Updated: 2024/05/15 18:13:10 by zqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/BSQ.h"

int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

t_Map	*allocate_map(void)
{
	t_Map	*map;

	map = malloc(sizeof(t_Map));
	if (!map)
	{
		print_error(2);
		exit(EXIT_FAILURE);
	}
	return (map);
}

void	read_parameters(int fd, char *param_buf, int *param_count)
{
	char	ch;

	while (read(fd, &ch, 1) && ch != '\n' && *param_count < 100)
	{
		param_buf[*param_count] = ch;
		(*param_count)++;
	}
	param_buf[*param_count] = '\0';
}
