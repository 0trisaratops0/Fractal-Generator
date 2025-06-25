/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 16:00:59 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 13:56:52 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

uint32_t	julia_pixel_color(t_data *d, t_pixel pixel)
{
	t_complex	c;
	t_complex	z;
	int			iterations;
	double		temp_real;

	c = pixel_to_complex(pixel, d->bounds, d->dim);
	z = c;
	iterations = 0;
	while ((z.real * z.real + z.imag * z.imag) <= 4.0 && iterations < MAX_ITER)
	{
		temp_real = z.real * z.real - z.imag * z.imag + d->julia_input.real;
		z.imag = 2.0 * z.real * z.imag + d->julia_input.imag;
		z.real = temp_real;
		iterations++;
	}
	return (calculate_color(iterations, z, d->palettes[d->color_idx]));
}

void	loop_through_julia_sets(t_data *d)
{
	if (d->julia_input.real + 0.1 > d->bounds.x_max)
	{
		d->julia_input.real = d->bounds.x_min;
		d->julia_input.imag += 0.1;
		if (d->julia_input.imag > d->bounds.y_max)
		{
			d->julia_input.imag = d->bounds.y_min;
		}
	}
	else
	{
		d->julia_input.real += 0.1;
	}
	plot_julia(d);
}

void	plot_julia(t_data *d)
{
	t_pixel	pixel;

	pixel.x = 0;
	while (pixel.x < d->dim.width)
	{
		pixel.y = 0;
		while (pixel.y < d->dim.height)
		{
			mlx_put_pixel(d->img, pixel.x, pixel.y, 
				julia_pixel_color(d, pixel));
			pixel.y++;
		}
		pixel.x++;
	}
}
