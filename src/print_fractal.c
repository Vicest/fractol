/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:45:03 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/27 18:39:30 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: Optimization pre-calc and load to mem all pixel components x and y in
//just one iteration to avoid repetitiveness of tasks.
#include "fractol.h"

static unsigned int	colorize_iteration(unsigned char nondiverging_iterations)
{
	return (64 * (unsigned int)nondiverging_iterations);
}

void	print_fractal(t_image *image, t_fractal fractal)
{
	t_pixel			current_pixel;
	t_point			adjusted_coords;
	unsigned char	nondiverging_iterations;
	//TODO temp for debug purposes
	t_point			center;
	center.x = 0;
	center.y = 0;

	current_pixel.y = -1;
	while (++current_pixel.y < HEIGHT)
	{
		adjusted_coords.y = get_ycoord(current_pixel.y, center.y, fractal.zoom);
		current_pixel.x = -1;
		while (++current_pixel.x < WIDTH)
		{
			adjusted_coords.x = get_xcoord(current_pixel.x, center.x, fractal.zoom);
			nondiverging_iterations = fractal.function(adjusted_coords);
			current_pixel.colour = colorize_iteration(
				nondiverging_iterations);
			set_pixel(image, current_pixel.x, current_pixel.y,
				current_pixel.colour);
		}
	}
}
