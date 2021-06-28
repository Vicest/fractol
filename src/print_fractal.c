/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:45:03 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/28 22:50:03 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: Optimization pre-calc and load to mem all pixel components x and y in
//just one iteration to avoid repetitiveness of tasks.
#include "fractol.h"
//#include <limits.h>

static unsigned int	colorize_iteration(unsigned char nondiverging_iterations)
{
	return ( 123123123 * ((unsigned int)nondiverging_iterations) % (255 * 255));
}

void	print_fractal(t_image *image, t_fractal fractal)
{
	t_pixel			current_pixel;
	t_point			adjusted_coords;
	unsigned char	nondiverging_iterations;

	current_pixel.y = -1;
	while (++current_pixel.y < HEIGHT)
	{
		adjusted_coords.y = get_ycoord(current_pixel.y, fractal.center.y,
			fractal.zoom);
		current_pixel.x = -1;
		while (++current_pixel.x < WIDTH)
		{
			adjusted_coords.x = get_xcoord(current_pixel.x, fractal.center.x,
				fractal.zoom);
			nondiverging_iterations = fractal.function(adjusted_coords);
			current_pixel.colour = colorize_iteration(
				nondiverging_iterations);
			set_pixel(image, current_pixel.x, current_pixel.y,
				current_pixel.colour);
		}
	}
}
