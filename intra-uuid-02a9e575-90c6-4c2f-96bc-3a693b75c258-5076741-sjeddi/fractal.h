/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/06 15:57:57 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 17:14:39 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include "MLX42/include/MLX42/MLX42.h"
# define MAX_ITER 1000
# define WIDTH 800
# define HEIGHT 600
# define MX_MIN -2.0
# define MY_MIN -1.5
# define MX_MAX 1.5
# define MY_MAX 1.5
# define JX_MIN -2
# define JX_MAX 2
# define JY_MIN -1.5
# define JY_MAX 1.5
# define BX_MIN -2.0
# define BX_MAX 1.0
# define BY_MIN -2.0
# define BY_MAX 2.0
# define COLOR1 0xF6E24EFF
# define COLOR2 0xF64E75FF
# define ZOOMFACTOR 1
# define NUM_COLORS 10

typedef struct s_store
{
	double	smooth_color;
	double	normalized_color;
	int		num_colors;
	int		segment;
}	t_store;

typedef struct s_dimensions
{
	int	width;
	int	height;
}	t_dimensions;

typedef struct s_coords
{
	double	x;
	double	y;
}	t_coords;

typedef enum s_fractal
{
	MANDELBROT,
	JULIA,
	BURNING
}	t_fractal;

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

typedef struct s_palette
{
	t_color	colors[6];
}	t_palette;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_mouse
{
	int32_t	x;
	int32_t	y;
}	t_mouse;

typedef struct s_bounds
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom_factor;
}	t_bounds;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				color_idx;
	t_pixel			pixel;
	uint32_t		iter;
	t_fractal		fractal;
	t_bounds		bounds;
	t_complex		complex;
	t_palette		palettes[5];
	t_complex		julia_input;
	t_dimensions	dim;
}	t_data;

void		ft_error(int err);
int			ft_isspace(int c);
int			ft_isdigit(int c);
double		ft_atof(char *str);
int			ft_strcmp(char *s1, char *s2);
void		plot_mandelbrot(t_data *d);
void		arg_checker(int argc, char **argv, t_data *d);
void		mlx_launcher(mlx_t *mlx, t_data *d);
int			main(int argc, char **argv);
t_complex	pixel_to_complex(t_pixel pixel, t_bounds bounds, t_dimensions dim);
void		ft_hook(void *param);
void		plot_julia(t_data *d);
void		plot_burning_ship(t_data *d);
uint32_t	calculate_color(int iterations, t_complex z, t_palette palette);
void		ft_zoom(t_data *d, double zoom_factor_change, 
				int32_t mouse_x, int32_t mouse_y);
void		redraw_fractal(t_data *d);
void		ft_scrollhook(double xdelta, double ydelta, void *param);
void		ft_keyhook(void *param);
void		ft_keyzoomout(void *param);
void		ft_keyzoomin(void *param);
void		ft_resizehook(int new_width, int new_height, void *param);
void		draw_fractal(t_data *d);
void		move_image_y(t_data *d, int direction, double mov_factor);
void		move_image_x(t_data *d, int direction, double move_factor);
void		loop_through_julia_sets(t_data *d);
void		init_data(t_data *d);
void		*ft_memcpy(void *dst, const void *src, size_t n);
double		calculate_smooth_color(int iterations, t_complex z);
double		calculate_normalized_color(double smooth_color);
int			calculate_segment(double normalized_color, int num_colors);
t_color		calculate_mixed_color(t_color color1, 
				t_color color2, double normalized_color);
uint32_t	calculate_final_color(t_color mix);

#endif