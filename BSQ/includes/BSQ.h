/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriera-c <nriera-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:19:25 by nriera-c          #+#    #+#             */
/*   Updated: 2024/05/15 15:19:26 by nriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct t_Map
{
	int		lines;
	char	empty;
	char	obstacle;
	char	full;
	char	**data;
}	t_Map;

void read_map_data(int fd, t_Map *map);
int	open_file(const char *file);
t_Map	*allocate_map(void);
void	read_parameters(int fd, char *param_buf, int *param_count);
t_Map	*read_map(const char *file);
t_Map	*read_map_from_stdin(void);
void	ft_putstr(char *str);
void	print_map(const t_Map *map);
int		print_error(int error);
void	ft_putchar(char c);
void	find_largest_square(t_Map *map);

#endif
