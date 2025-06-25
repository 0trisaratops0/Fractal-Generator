/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burning_ship.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 17:02:24 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 17:20:33 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

uint32_t	burning_ship_pixel_color(t_pixel pixel, 
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
		z.imag = fabs(2.0 * z.real * z.imag) + c.imag;
		z.real = temp_real;
		iterations++;
	}
	return (calculate_color(iterations, z, palette));
}

void	plot_burning_ship(t_data *d)
{
	t_pixel	pixel;

	pixel.x = 0;
	while (pixel.x < d->dim.width)
	{
		pixel.y = 0;
		while (pixel.y < d->dim.height)
		{
			mlx_put_pixel(d->img, pixel.x, pixel.y, burning_ship_pixel_color(
					pixel, d->bounds, d->dim, d->palettes[d->color_idx]));
			pixel.y++;
		}
		pixel.x++;
	}
}
