/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/12 21:40:36 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 13:23:35 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*d;
	int32_t	mouse_x;
	int32_t	mouse_y;

	d = (t_data *)param;
	xdelta++;
	mlx_get_mouse_pos(d->mlx, &mouse_x, &mouse_y);
	if (ydelta > 0)
		ft_zoom(d, 1.1, mouse_x, mouse_y);
	else if (ydelta < 0)
		ft_zoom(d, 0.9, mouse_x, mouse_y);
	draw_fractal(d);
}

void	ft_keyhook(void *param)
{
	t_data	*d;

	d = param;
	if (mlx_is_key_down(d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(d->mlx);
	if (mlx_is_key_down(d->mlx, MLX_KEY_UP))
		move_image_y(d, -1, 0.1);
	if (mlx_is_key_down(d->mlx, MLX_KEY_DOWN))
		move_image_y(d, 1, 0.1);
	if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT))
		move_image_x(d, 1, 0.1);
	if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT))
		move_image_x(d, -1, 0.1);
	if (d->fractal == JULIA && mlx_is_key_down(d->mlx, MLX_KEY_SPACE))
		loop_through_julia_sets(d);
	if (mlx_is_key_down(d->mlx, MLX_KEY_ENTER))
	{
		d->color_idx ++;
		if (d->color_idx > 3)
			d->color_idx = 0;
		draw_fractal(d);
	}
}

void	ft_resizehook(int new_width, int new_height, void *param)
{
	t_data	*d;

	d = param;
	d->dim.width = new_width;
	d->dim.height = new_height;
	d->mlx->width = new_width;
	d->mlx->height = new_height;
	mlx_resize_image(d->img, new_width, new_height);
	if (d->dim.width > d->dim.height)
		d->bounds.x_max = d->bounds.x_min + (d->bounds.y_max - d->bounds.y_min) 
			* d->dim.width / d->dim.height;
	else
		d->bounds.y_max = d->bounds.y_min + (d->bounds.x_max - d->bounds.x_min) 
			* d->dim.height / d->dim.width;
	draw_fractal(d);
}
