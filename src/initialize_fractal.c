/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:24:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/02 22:57:54 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <limits.h>

void	initialize_fractal(t_fractal *fractal, int argn, char **fractal_argv)
{
	fractal->zoom = 1;
	fractal->max_iter = 0xFF;
	fractal->center.x = 0;
	fractal->center.y = 0;
	if (!ft_strcmp("mandelbrot", fractal_argv[0]))
		load_mandelbrot(fractal, argn - 1, &(fractal_argv[1]));
	else if (!ft_strcmp("multibrot", fractal_argv[0]))
		load_multibrot(fractal, argn - 1, &(fractal_argv[1]));
	else if (!ft_strcmp("julia", fractal_argv[0]))
		load_julia(fractal, argn - 1, &(fractal_argv[1]));
	else if (!ft_strcmp("mandelbar", fractal_argv[0]))
		load_mandelbar(fractal, argn - 1, &(fractal_argv[1]));
	else if (!ft_strcmp("burning_ship", fractal_argv[0]))
		load_burning_ship(fractal, argn - 1, &(fractal_argv[1]));
}
