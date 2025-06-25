/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/06 15:49:03 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 16:53:42 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_zoom(t_data *d, double zoom_factor_change, 
	int32_t mouse_x, int32_t mouse_y)
{
	t_coords	range;
	t_coords	center;
	t_coords	new_range;

	range.x = d->bounds.x_max - d->bounds.x_min;
	range.y = d->bounds.y_max - d->bounds.y_min;
	center.x = d->bounds.x_min + range.x * (double)mouse_x / d->dim.width;
	center.y = d->bounds.y_min + range.y * (double)mouse_y / d->dim.height;
	new_range.x = range.x / zoom_factor_change;
	new_range.y = range.y / zoom_factor_change;
	d->bounds.x_min = center.x - new_range.x / 2.0;
	d->bounds.x_max = center.x + new_range.x / 2.0;
	d->bounds.y_min = center.y - new_range.y / 2.0;
	d->bounds.y_max = center.y + new_range.y / 2.0;
}

void	move_image_y(t_data *d, int direction, double mov_factor)
{
	double	y_range;
	double	movement;

	y_range = d->bounds.y_max - d->bounds.y_min;
	movement = y_range * mov_factor * direction;
	d->bounds.y_min += movement;
	d->bounds.y_max += movement;
	draw_fractal(d);
}

void	move_image_x(t_data *d, int direction, double mov_factor)
{
	double	x_range;
	double	movement;

	x_range = d->bounds.x_max - d->bounds.x_min;
	movement = x_range * mov_factor * direction;
	d->bounds.x_min += movement;
	d->bounds.x_max += movement;
	draw_fractal(d);
}
