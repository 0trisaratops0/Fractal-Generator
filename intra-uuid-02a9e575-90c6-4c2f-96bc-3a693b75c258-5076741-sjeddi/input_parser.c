/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 16:00:42 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 17:42:03 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_palette(t_data *d, int index)
{
	t_palette	*palette;
	t_color		palette_colors[5][6];

	palette = &d->palettes[index];
	if (index == 0)
		ft_memcpy(palette_colors[index], (t_color[]){{255, 0, 255}, 
		{0, 255, 255}, {255, 165, 0}, {0, 255, 0}, 
		{255, 255, 0}, {255, 0, 0}}, sizeof(t_color) * 6);
	else if (index == 1)
		ft_memcpy(palette_colors[index], (t_color[]){{164, 244, 225}, 
		{164, 223, 244}, {164, 183, 244}, {185, 164, 244}, 
		{225, 164, 244}, {244, 164, 223}}, sizeof(t_color) * 6);
	else if (index == 2)
		ft_memcpy(palette_colors[index], (t_color[]){{209, 164, 244}, 
		{244, 164, 239}, {244, 164, 199}, {244, 169, 164}, 
		{244, 209, 164}, {239, 244, 164}}, sizeof(t_color) * 6);
	else if (index == 3)
		ft_memcpy(palette_colors[index], (t_color[]){{187, 170, 223}, 
		{161, 127, 118}, {187, 170, 223}, {161, 127, 118}, 
		{187, 170, 223}, {161, 127, 118}}, sizeof(t_color) * 6);
	else if (index == 4)
		ft_memcpy(palette_colors[index], (t_color[]){{43, 85, 142}, 
		{166, 3, 84}, {43, 85, 142}, {166, 3, 84}, 
		{43, 85, 142}, {166, 3, 84}}, sizeof(t_color) * 6);
	ft_memcpy(palette, palette_colors[index], sizeof(t_palette));
}

void	init_data(t_data *d)
{
	d->dim.width = WIDTH;
	d->dim.height = HEIGHT;
	if (d->fractal == MANDELBROT)
	{
		d->bounds.x_min = MX_MIN;
		d->bounds.x_max = MX_MAX;
		d->bounds.y_min = MY_MIN;
		d->bounds.y_max = MY_MAX;
	}
	else if (d->fractal == JULIA)
	{
		d->bounds.x_min = JX_MIN;
		d->bounds.x_max = JX_MAX;
		d->bounds.y_min = JY_MIN;
		d->bounds.y_max = JY_MAX;
	}
	else if (d->fractal == BURNING)
	{
		d->bounds.x_min = BX_MIN;
		d->bounds.x_max = BX_MAX;
		d->bounds.y_min = BY_MIN;
		d->bounds.y_max = BY_MAX;
	}
}

void	process_julia_args(t_data *d, int argc, char **argv)
{
	if (argc < 4 || argc > 5)
		ft_error(1);
	d->fractal = JULIA;
	d->julia_input.real = ft_atof(argv[2]);
	d->julia_input.imag = ft_atof(argv[3]);
	if (d->julia_input.real < JX_MIN || d->julia_input.real > JX_MAX 
		|| d->julia_input.imag < JY_MIN || d->julia_input.imag > JY_MAX)
		ft_error(1);
	if (argc == 5)
		init_palette(d, atof(argv[4]));
	else
		init_palette(d, 0);
}

void	arg_checker(int argc, char **argv, t_data *d)
{
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
	{
		if (argc < 2 || argc > 3)
			ft_error(0);
		d->fractal = MANDELBROT;
		if (argc == 3)
			init_palette(d, ft_atof(argv[2]));
		else
			init_palette(d, 0);
	}
	else if (ft_strcmp("burning", argv[1]) == 0)
	{
		if (argc < 2 || argc > 3)
			ft_error(0);
		d->fractal = BURNING;
		if (argc == 3)
			init_palette(d, atof(argv[2]));
		else
			init_palette(d, 0);
	}
	else if (ft_strcmp("julia", argv[1]) == 0)
		process_julia_args(d, argc, argv);
	else
		ft_error(0);
	init_data(d);
}

void	draw_fractal(t_data *d)
{
	if (d->fractal == MANDELBROT)
		plot_mandelbrot(d);
	else if (d->fractal == JULIA)
		plot_julia(d);
	else if (d->fractal == BURNING)
		plot_burning_ship(d);
}
