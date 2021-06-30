/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:45:03 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/30 13:23:47 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: Optimization pre-calc and load to mem all pixel components x and y in
//just one iteration to avoid repetitiveness of tasks.
#include "fractol.h"
//#include <limits.h>

/*
static unsigned int	colorize_iteration(unsigned int nondiverging_iterations)
{
	const unsigned int	range = nondiverging_iterations % 30;

	if (nondiverging_iterations == 0)
		return (0);
	if (range < 10)
		return ((unsigned int)nondiverging_iterations % 256);
	if (range < 20)
		return ((unsigned int)nondiverging_iterations % 256) * 256;
	return ((unsigned int)nondiverging_iterations % 256 * 256 * 256);
}
*/

static void	precalculate_width_coords(double *width_coord, t_fractal fractal)
{
	unsigned int	i;

	i = -1;
	while (++i < WIDTH)
		width_coord[i] = get_xcoord(i, fractal.center.x, fractal.zoom);
}

void	print_fractal(t_image *image, t_fractal fractal)
{
	t_pixel			current_pixel;
	t_point			adjusted_coords;
	double			width_coord[WIDTH];
	unsigned int	nondiverging_iterations;

	precalculate_width_coords(width_coord, fractal);
	current_pixel.y = -1;
	while (++current_pixel.y < HEIGHT)
	{
		adjusted_coords.y = get_ycoord(current_pixel.y, fractal.center.y,
			fractal.zoom);
		current_pixel.x = -1;
		while (++current_pixel.x < WIDTH)
		{
			adjusted_coords.x = width_coord[current_pixel.x];
			nondiverging_iterations = fractal.function(adjusted_coords, fractal);
			current_pixel.colour = colorize(
				nondiverging_iterations);
			set_pixel(image, current_pixel.x, current_pixel.y,
				current_pixel.colour);
		}
	}
}
