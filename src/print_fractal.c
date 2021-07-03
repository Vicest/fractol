/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:45:03 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 21:50:03 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	precalculate_width_coords(double *width_coord, t_fractal fractal)
{
	unsigned int	i;

	i = -1;
	while (++i < WIDTH)
		width_coord[i] = scale(i, WIDTH, fractal.zoom);
}

void	print_fractal(t_image *image, t_fractal fractal)
{
	t_pixel			current_pixel;
	t_point			scaled_coords;
	double			width_coord[WIDTH];
	unsigned int	nondiverging_iterations;

	precalculate_width_coords(width_coord, fractal);
	current_pixel.y = -1;
	while (++current_pixel.y < HEIGHT)
	{
		scaled_coords.y = scale(current_pixel.y, HEIGHT, fractal.zoom)
			+ fractal.center.y;
		current_pixel.x = -1;
		while (++current_pixel.x < WIDTH)
		{
			scaled_coords.x = width_coord[current_pixel.x] + fractal.center.x;
			nondiverging_iterations = fractal.function(scaled_coords, fractal);
			current_pixel.colour = colorize(nondiverging_iterations,
					fractal.max_iter, fractal.color_shift);
			set_pixel(image, current_pixel.x, current_pixel.y,
				current_pixel.colour);
		}
	}
}
