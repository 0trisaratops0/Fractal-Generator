/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 17:50:06 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 14:36:31 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	pixel_to_complex(t_pixel pixel, t_bounds bounds, t_dimensions dim)
{
	t_complex	c;

	c.real = bounds.x_min + (bounds.x_max - bounds.x_min) * pixel.x / dim.width;
	c.imag = bounds.y_min + (bounds.y_max - bounds.y_min) 
		* pixel.y / dim.height;
	return (c);
}

uint32_t	mandelbrot_pixel_color(t_pixel pixel, 
	t_bounds bounds, t_dimensions dim, t_palette palette)
{
	t_complex	c;
	t_complex	z;
	int			iterations;
	double		temp_real;

	c = pixel_to_complex(pixel, bounds, dim);
	z.real = 0.0;
	z.imag = 0.0;
	iterations = 0;
	while ((z.real * z.real + z.imag * z.imag) <= 4.0 && iterations < MAX_ITER)
	{
		temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp_real;
		iterations++;
	}
	return (calculate_color(iterations, z, palette));
}

void	plot_mandelbrot(t_data *d)
{
	t_pixel	pixel;

	pixel.x = 0;
	while (pixel.x < d->dim.width)
	{
		pixel.y = 0;
		while (pixel.y < d->dim.height)
		{
			mlx_put_pixel(d->img, pixel.x, pixel.y, mandelbrot_pixel_color(
					pixel, d->bounds, d->dim, d->palettes[d->color_idx]));
			pixel.y++;
		}
		pixel.x++;
	}
}
