/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:24:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/27 15:36:49 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

void	initialize_fractal(t_fractal *fractal, char *fractal_argument)
{
	if (!ft_strcmp("mandelbrot", fractal_argument))
	{
		fractal->function = mandelbrot;
		fractal->zoom = 0.0125;
	} else if (!ft_strcmp("julia", fractal_argument))
	{
		fractal->function = julia;
		fractal->zoom = 0.0125;
	}
}
