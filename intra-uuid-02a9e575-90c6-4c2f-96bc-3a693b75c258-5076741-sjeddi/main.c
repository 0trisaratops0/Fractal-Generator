/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/06 13:32:48 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 16:40:19 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mlx_launcher(mlx_t *mlx, t_data *d)
{
	if (!mlx)
		ft_error(2);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	d->mlx = mlx;
	d->img = mlx_new_image(mlx, d->dim.width, d->dim.height);
	if (!d->img)
		ft_error(2);
}

void	initialize(int argc, char **argv, t_data *d)
{
	arg_checker(argc, argv, d);
	mlx_launcher(mlx_init(d->dim.width, d->dim.height, "Fractol", true), d);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc < 2 || argc > 5)
		ft_error(0);
	initialize(argc, argv, &d);
	mlx_image_to_window(d.mlx, d.img, 0, 0);
	if (mlx_image_to_window(d.mlx, d.img, 0, 0) < 0)
		ft_error(2);
	draw_fractal(&d);
	mlx_scroll_hook(d.mlx, &ft_scrollhook, &d);
	mlx_loop_hook(d.mlx, &ft_keyhook, &d);
	mlx_resize_hook(d.mlx, &ft_resizehook, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	exit (MLX_SUCCESS);
}
