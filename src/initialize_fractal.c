/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:24:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/30 13:00:35 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

void	initialize_fractal(t_fractal *fractal, int argn, char **fractal_argv)
{
	(void)argn;
	fractal->zoom = 0.005;
	if (!ft_strcmp("mandelbrot", fractal_argv[0]))
	{
		fractal->function = mandelbrot;
		fractal->zoom = 0.005;
		fractal->center.x = -0.75;
		fractal->center.y = 0;
	} else if (!ft_strcmp("julia", fractal_argv[0]))
	{
		fractal->center.x = -0.5;
		fractal->center.y = 0;
		fractal->init.x = 0.285;
		fractal->init.y = 0.1;
		if (argn >= 2)
		{
			fractal->init.x = ft_atof(fractal_argv[1]);
			if (argn >= 3)
				fractal->init.y = ft_atof(fractal_argv[2]);
		}
		fractal->function = julia;
	//} else if (!ft_strcmp("newton", fractal_argv[0]))
	//{
	//	fractal->function = newton;
	}
}
