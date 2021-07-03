/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:03:12 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 23:34:17 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_color(t_rgb *color, unsigned char r, unsigned char g,
		unsigned char b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

static void	shift_colors(t_rgb *color, char shift)
{
	t_rgb	original;

	set_color(&original, color->r, color->g, color->b);
	if (shift == 1)
		set_color(color, color->g, color->b, color->r);
	else if (shift == 2)
		set_color(color, color->b, color->r, color->g);
}

unsigned int	colorize(unsigned int iterations, unsigned int max_iter,
		char shift)
{
	t_rgb				color;
	const unsigned int	range_size = max_iter / 4;
	const double		scale = 255 / range_size;
	const unsigned int	interpolated_value = ft_min(
			((unsigned int)(scale * iterations)), 0xFF);

	if (iterations == max_iter)
		return (0);
	else if (iterations < range_size)
		set_color(&color, 0, interpolated_value, 255);
	else if (iterations < 2 * range_size)
		set_color(&color, 0, 255, 255 - interpolated_value);
	else if (iterations < 3 * range_size)
		set_color(&color, interpolated_value, 255, 0);
	else
		set_color(&color, 255, 255 - interpolated_value, 0);
	shift_colors(&color, shift);
	return ((color.r << 16) + (color.g << 8) + (color.b << 0));
}
