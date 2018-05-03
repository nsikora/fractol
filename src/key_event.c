/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:30:31 by nsikora           #+#    #+#             */
/*   Updated: 2018/05/01 11:23:34 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "mlx.h"
#include "libft.h"

int		ft_mouse_scroll(int key, int x, int y, t_dataset *data)
{
	(void)x;
	(void)y;
	if (data->lock == 0)
		return (0);
	mlx_clear_window(data->mlx, data->win);
	if (key == 4 && data->iter <= 2147482647)
		data->iter = data->iter + 200;
	if (key == 5 && data->iter >= 200)
		data->iter = data->iter - 200;
	display_window(data);
	return (0);
}

void	julia_shape_shifter(int key, t_dataset *data)
{
	if (data->iter == 0)
	{
		if (key == 1)
			data->a = data->a + 0.01;
		if (key == 13)
			data->a = data->a - 0.01;
		if (key == 0)
			data->b = data->b + 0.01;
		if (key == 2)
			data->b = data->b - 0.01;
	}
}

int		move_fractale(int key, t_dataset *data)
{
	float	cp;
	int		tmp;

	if (data->lock == 0)
		return (0);
	cp = 0.1;
	tmp = data->iter;
	while (tmp >= 1000)
	{
		cp = cp / 10;
		tmp = tmp / 1000;
	}
	if (key == 125)
		data->c_height = data->c_height - cp;
	if (key == 126)
		data->c_height = data->c_height + cp;
	if (key == 123)
		data->c_width = data->c_width - cp;
	if (key == 124)
		data->c_width = data->c_width + cp;
	return (0);
}

int		ft_mouse_event(int x, int y, t_dataset *data)
{
	if (data->lock == 0)
	{
		data->a = (((float)x / (float)data->win_x) * 4) - 2;
		data->b = (((float)y / (float)data->win_y) * 4) - 2;
		display_window(data);
	}
	return (0);
}

int		ft_key_event(int key, t_dataset *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (key == 53)
		free_for_all(data);
	if (key == 49)
	{
		if (data->i == 6)
			data->i = 0;
		else
			data->i++;
	}
	if (key == 36)
		data->lock = 1;
	if (key == 1 || key == 13 || key == 2 || key == 0)
		julia_shape_shifter(key, data);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_fractale(key, data);
	if (key == 69 && data->iter <= 2147482647 && data->lock == 1)
		data->iter = data->iter + 200;
	if (key == 78 && data->iter >= 200 && data->lock == 1)
		data->iter = data->iter - 200;
	if (data->iter == 0 && key == 69 && key >= 123 && key <= 126)
		return (0);
	else
		display_window(data);
	return (0);
}
