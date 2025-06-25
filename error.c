/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 15:30:17 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/08/19 17:40:04 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
			write(fd, &s[i++], 1);
}

void	ft_error(int err)
{
	if (err == 0)
		ft_putstr_fd("invalid parameters.\n"
			"try again.\n"
			"for mandelbrot, type './fractal', followed by 'mandelbrot'.\n"
			"for burning ship, type './fractal', followed by 'burning'\n"
			"for julia, type './fractal' followed by 'julia',\n"
			"then enter 2 digits within the correct range [-2.0, 2.0]", 1);
	else if (err == 1)
		ft_putstr_fd("for julia, make sure you've entered\n"
			"your parameters correctly.\n"
			"type './fractal', followed by 'julia',\n"
			"then enter 2 digits within the correct range [-2.0, 2.0]", 1);
	exit(EXIT_FAILURE);
}
