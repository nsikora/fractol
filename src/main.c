/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:03:14 by nsikora           #+#    #+#             */
/*   Updated: 2018/05/01 11:24:07 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "get_next_line.h"
#include "libft.h"
#include "fractol.h"
#include <stdlib.h>

void			free_for_all(t_dataset *data)
{
	mlx_destroy_image(data->mlx, data->image);
	mlx_destroy_window(data->mlx, data->win);
	free(data->color);
	free(data);
	exit(0);
}

int				main(int ac, char **av)
{
	t_dataset	*data;

	if (ac != 2 || (match(av[1], "-mandelbrot") == 1
		&& match(av[1], "-julia") == 1 && match(av[1], "-burning_ship") == 1))
	{
		ft_putendl("usage: ./fractol -burning_ship");
		ft_putendl("                 -julia");
		ft_putendl("                 -mandelbrot");
		return (0);
	}
	if ((data = malloc(sizeof(t_dataset))) == 0)
		return (1);
	declare_data(data, av[1]);
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "fractol");
	display_window(data);
	return (0);
}
