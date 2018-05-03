/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:41:38 by nsikora           #+#    #+#             */
/*   Updated: 2018/05/01 09:54:52 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct		s_dataset
{
	float			a;
	float			b;
	float			c_width;
	float			c_height;
	int				iter;
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	char			*name;
	void			*image;
	unsigned int	*image_str;
	int				*color;
	int				i;
	char			lock;
}					t_dataset;

typedef struct		s_mandelbrot
{
	int				x;
	int				y;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			image_x;
	float			image_y;
	float			zoom_y;
	float			zoom_x;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			i;
	float			tmp;
	float			iteration_max;
	float			burning_save;
}					t_mandelbrot;

typedef struct		s_blob
{
	t_dataset		*data;
	t_mandelbrot	*mandel;
	char			init;
}					t_blob;

# define ABS(i) ((i < 0) ? -i : i)

void				declare_data(t_dataset *data, char *str);
void				display_window(t_dataset *data);
int					ft_key_event(int key, t_dataset *data);
int					ft_mouse_event(int x, int y, t_dataset *data);
int					ft_mouse_scroll(int key, int x, int y, t_dataset *data);
int					mandelbrot(t_dataset *data);
int					julia(t_dataset *data);
int					burning(t_dataset *data);
int					match(char *str, char *ptr);
void				display_info(t_dataset *data, t_mandelbrot *mandel);
void				free_for_all(t_dataset *data);

#endif
