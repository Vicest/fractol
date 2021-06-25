/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:45:03 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/25 21:25:01 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: Optimization pre-calc and load to mem all pixel components x and y in
//just one iteration to avoid repetitiveness of tasks.
#include "fractol.h"

static double	get_xcoord(unsigned int coord, t_point center, double zoom)
{
	return (fit_coord = zoom * (coord - WIDTH * 0.5 + 0.5 - center.x));
}

static double	get_ycoord(unsigned int coord, t_point center, double zoom)
{
	return (fit_coord = zoom * (coord - HEIGHT * 0.5 + 0.5 - center.y));
}

static unsigned int	colorize_iteration(unsigned char nondiverging_iterations)
{
	return (3 * (unsigned int)nndiverging_iterations);
}

void	print_fractal(void *image, void *(t_point)fractal_funct, )
{
	t_pixel			current_pixel;
	t_point			adjusted_coords;
	unsigned char	nondiverging_iterations;

	current_pixel.pixel_y = -1;
	while (++current_pixel.pixel_y < HEIGHT)
	{
		adjusted_coords.y = gety_coord(current_pixel.pixel_y, center, zoom);
		current_pixel.pixel_x = -1;
		while (++current_pixel.pixel_x < WIDTH)
		{
			adjusted_coords.x = getx_coord(current_pixel.pixel_y, center, zoom);
			nondiverging_iterations = iterate_fractal(fractal_funct,
				adjusted_coords);
			current_pixel.pixel_colour = colorize_iteration(
				nondiverging_iterations);
			set_pixel(image, current_pixel.x, current_pixel.y,
				current_pixel.colour);
		}
	}
}
