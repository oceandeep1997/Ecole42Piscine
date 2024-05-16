/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriera-c <nriera-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:14:27 by nriera-c          #+#    #+#             */
/*   Updated: 2024/05/15 14:14:28 by nriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ.h"

int	print_error(int error)
{
	if (error == 1)
		ft_putstr("File error\n");
	else if (error == 2)
		ft_putstr("Memory error\n");
	else if (error == 3)
		ft_putstr("Map error\n");
	else if (error == 4)
		ft_putstr("Program usage: ./bsq <input_file> or use standard input.\n");
	else if (error == 5)
		ft_putstr("Unexpected character found in map data: ");
	return (error);
}
