/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:16:48 by nsikora           #+#    #+#             */
/*   Updated: 2018/05/01 11:23:22 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "libft.h"
#include "fractol.h"
#include "mlx.h"

void				display_julia(t_dataset *data, t_mandelbrot *mandel)
{
	if (mandel->i == mandel->iteration_max)
		data->image_str[mandel->x + mandel->y * data->win_x] = 16768477;
	else
		data->image_str[mandel->x + mandel->y * data->win_x] =
	mandel->i * data->color[data->i];
}

void				calculate_complex_j(t_mandelbrot *copy, t_dataset *data)
{
	while (copy->z_r * copy->z_r + copy->z_i * copy->z_i < 4
	&& copy->i < copy->iteration_max)
	{
		copy->tmp = copy->z_r;
		copy->z_r = (copy->z_r * copy->z_r) - (copy->z_i * copy->z_i) + data->a;
		copy->z_i = (2 * copy->z_i * copy->tmp) + data->b;
		copy->i++;
	}
	display_julia(data, copy);
}

void				*calculate_julia(void *arg)
{
	t_mandelbrot	*mandel;
	t_mandelbrot	copy;
	t_dataset		*data;
	t_blob			*blob;

	mandel = ((t_blob *)arg)->mandel;
	data = ((t_blob *)arg)->data;
	blob = (t_blob *)arg;
	copy.x = mandel->x;
	copy.image_x = mandel->image_x;
	copy.iteration_max = mandel->iteration_max;
	blob->init = 1;
	while (copy.x < copy.image_x)
	{
		copy.y = 0;
		while (copy.y++ < mandel->image_y)
		{
			copy.z_r = (copy.x / mandel->zoom_x) + mandel->x1;
			copy.z_i = (copy.y / mandel->zoom_y) + mandel->y1;
			copy.i = 0;
			calculate_complex_j(&copy, data);
		}
		copy.x++;
	}
	return (NULL);
}

int					algo_julia(t_mandelbrot *mandel, t_dataset *data,
					int x, int image_x)
{
	pthread_t		thread[(int)mandel->image_x];
	t_blob			*blob;

	if ((blob = malloc(sizeof(t_blob))) == 0)
		return (1);
	image_x = mandel->image_x / 8;
	mandel->image_x = 0;
	while (x < 8)
	{
		mandel->image_x += image_x;
		blob->mandel = mandel;
		blob->data = data;
		blob->init = 0;
		pthread_create(&(thread[mandel->x]), NULL, calculate_julia, blob);
		while (blob->init == 0)
			;
		mandel->x += image_x;
		x++;
	}
	x = 0;
	while (x < mandel->image_x)
		pthread_join(thread[x++], NULL);
	free(blob);
	return (0);
}

int					julia(t_dataset *data)
{
	t_mandelbrot	*mandel;

	if ((mandel = malloc(sizeof(t_mandelbrot))) == 0)
		return (1);
	mandel->x = 0;
	mandel->y = 0;
	mandel->x1 = -1.55 + data->c_width;
	mandel->x2 = 1.55 + data->c_height;
	mandel->y1 = -1.55 - data->c_height;
	mandel->y2 = 1.55 - data->c_width;
	mandel->image_x = data->win_x;
	mandel->image_y = data->win_y;
	mandel->iteration_max = 200 + data->iter * 3;
	mandel->zoom_x = mandel->image_x / (mandel->x2 - mandel->x1) + data->iter;
	mandel->zoom_y = mandel->image_y / (mandel->y2 - mandel->y1) + data->iter;
	if (algo_julia(mandel, data, 0, 0) == 1)
		return (1);
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	display_info(data, mandel);
	free(mandel);
	return (0);
}
