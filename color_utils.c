/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 16:00:22 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 14:42:41 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	calculate_smooth_color(int iterations, t_complex z)
{
	return ((double)iterations - 
		log(log(sqrt(z.real * z.real + z.imag * z.imag))) / log(2.0));
}

double	calculate_normalized_color(double smooth_color)
{
	return (0.5 + 0.5 * sin((smooth_color / 200) * M_PI));
}

int	calculate_segment(double normalized_color, int num_colors)
{
	return ((int)(normalized_color * (num_colors - 1)));
}

t_color	calculate_mixed_color(t_color color1, 
	t_color color2, double normalized_color)
{
	t_color	mix;

	mix.r = color1.r + normalized_color * (color2.r - color1.r);
	mix.g = color1.g + normalized_color * (color2.g - color1.g);
	mix.b = color1.b + normalized_color * (color2.b - color1.b);
	return (mix);
}

uint32_t	calculate_final_color(t_color mix)
{
	return (((uint32_t)mix.r << 24) | ((uint32_t)mix.g << 16) 
		| ((uint32_t)mix.b << 8) | 0xFF);
}
