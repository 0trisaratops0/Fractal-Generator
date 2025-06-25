/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 14:40:31 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 17:21:20 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

uint32_t	calculate_color(int iterations, t_complex z, t_palette palette)
{
	t_store	store;
	t_color	color1;
	t_color	color2;
	t_color	mix;

	store.num_colors = sizeof(palette.colors) / sizeof(palette.colors[0]);
	if (iterations == MAX_ITER)
		return (0x000000FF);
	else
	{
		store.smooth_color = calculate_smooth_color(iterations, z);
		store.normalized_color = calculate_normalized_color(store.smooth_color);
		store.segment = calculate_segment(store.normalized_color, 
				store.num_colors);
		store.normalized_color = store.normalized_color * 
			(store.num_colors - 1) - store.segment;
		color1 = palette.colors[store.segment];
		color2 = palette.colors[store.segment + 1];
		mix = calculate_mixed_color(color1, color2, store.normalized_color);
		return (calculate_final_color(mix));
	}
}
