/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:24:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/28 22:26:04 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

void	initialize_fractal(t_fractal *fractal, char *fractal_argument)
{
	fractal->zoom = 0.005;
	fractal->center.x = -0.5;
	fractal->center.y = 0;
	if (!ft_strcmp("mandelbrot", fractal_argument))
	{
		fractal->function = mandelbrot;
		fractal->zoom = 0.005;
		fractal->center.x = -0.5;
		fractal->center.y = 0;
	} else if (!ft_strcmp("julia", fractal_argument))
	{
		fractal->function = julia;
	}
}
