/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:03:12 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/02 20:16:47 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <limits.h>

unsigned int	colorize(unsigned int iterations, unsigned int max_iter)
{
	t_rgb				color_channel;
	const unsigned int	range_size = max_iter / 4;
	const double		scale = 255 / range_size;

	color_channel.r = 0;
	color_channel.g = 0;
	color_channel.b = 0;
	if (iterations == max_iter)
		return (0);
	else if (iterations < range_size)
	{
		color_channel.g = ft_min(((unsigned int)(scale * iterations)), 0xFF);
		color_channel.b = 255;
	}
	else if (iterations < 2 * range_size)
	{
		color_channel.g = 255;
		color_channel.b = 255 - ft_min(
				(unsigned int)(scale * (iterations % range_size)), 0xFF);
	}
	else if (iterations < 3 * range_size)
	{
		color_channel.r = ft_min(
				(unsigned int)(scale * (iterations % range_size)), 0xFF);
		color_channel.g = 255;
	}
	else
	{
		color_channel.r = 255;
		color_channel.g = 255 - ft_min(
				(unsigned int)(scale * (iterations % range_size)), 0xFF);
	}
	return ((color_channel.r << 16) + (color_channel.g << 8) + (color_channel.b));
}
