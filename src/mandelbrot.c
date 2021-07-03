/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:07:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 21:01:33 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"

void	load_mandelbrot(t_fractal *fractal, int argn, char **argv)
{
	(void)argn;
	(void)argv;
	fractal->center.x = -0.5;
	fractal->max_iter = 0x7F;
	fractal->function = mandelbrot;
}

unsigned int	mandelbrot(t_point point, t_fractal fractal)
{
	unsigned int	i;
	t_complex		z;
	t_complex		c;

	ft_zset(&z, 0.0, 0.0);
	ft_zset(&c, point.x, point.y);
	i = 0;
	while (z.re * z.re + z.im * z.im < fractal.escape_radius
		&& i < fractal.max_iter)
	{
		i++;
		ft_zmul(&z, &z, &z);
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
