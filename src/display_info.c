/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:01:47 by nsikora           #+#    #+#             */
/*   Updated: 2018/05/01 11:22:46 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "fractol.h"

void	display_info(t_dataset *data, t_mandelbrot *mandel)
{
	char *str;

	str = ft_itoa(mandel->iteration_max);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, (data->name + 1));
	mlx_string_put(data->mlx, data->win, 10, 30, 0xFFFFFF, "Iterations:");
	mlx_string_put(data->mlx, data->win, 130, 30, 0xFFFFFF, str);
	mlx_string_put(data->mlx, data->win, 10, 70, 0xFFFFFF,
	"Press arrow keys to move");
	mlx_string_put(data->mlx, data->win, 10, 90, 0xFFFFFF,
	"Press +/- or scroll to zoom/unzoom");
	mlx_string_put(data->mlx, data->win, 10, 110, 0xFFFFFF,
	"Press space to swap color");
	mlx_string_put(data->mlx, data->win, 10, 130, 0xFFFFFF,
	"Press ESC to exit programm");
	if (match(data->name, "-julia") == 0)
		mlx_string_put(data->mlx, data->win, 10, 50, 0xFFFFFF,
		"FIRST, press ENTER to lock shape");
	free(str);
}
