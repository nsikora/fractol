/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:14:54 by nsikora           #+#    #+#             */
/*   Updated: 2018/05/01 11:22:32 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdlib.h>

void	init_color(t_dataset *data)
{
	data->color[0] = 262144;
	data->color[1] = 65536;
	data->color[2] = 512;
	data->color[3] = 197379;
	data->color[4] = 16774885;
	data->color[5] = 16773375;
	data->color[6] = 197888;
}

void	declare_data(t_dataset *data, char *str)
{
	int bpp;
	int	s_l;
	int	endian;

	data->mlx = mlx_init();
	data->win_x = 1350;
	data->win_y = 1200;
	data->c_width = 0;
	data->c_height = 0;
	data->iter = 0;
	data->name = str;
	data->a = -0.8;
	data->b = 0.2;
	data->color = malloc(sizeof(int) * 8);
	data->i = 0;
	data->lock = 0;
	init_color(data);
	data->image = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->image_str = (unsigned int *)(mlx_get_data_addr(data->image,
	&bpp, &s_l, &endian));
}
