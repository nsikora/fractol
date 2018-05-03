/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lel.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:21:53 by nsikora           #+#    #+#             */
/*   Updated: 2018/05/01 11:22:59 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "mlx.h"
#include "libft.h"

void	display_window(t_dataset *data)
{
	if (match(data->name, "-mandelbrot") == 0)
	{
		mandelbrot(data);
		data->lock = 1;
	}
	if (match(data->name, "-julia") == 0)
		julia(data);
	if (match(data->name, "-burning_ship") == 0)
	{
		burning(data);
		data->lock = 1;
	}
	mlx_key_hook(data->win, ft_key_event, data);
	mlx_hook(data->win, 6, 1L << 6, ft_mouse_event, data);
	mlx_hook(data->win, 4, 1L << 2, ft_mouse_scroll, data);
	mlx_loop(data->mlx);
}
