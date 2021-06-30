/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:07:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/30 14:56:41 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"
#include <math.h>
#include <limits.h>

unsigned char	mandelbrot(t_point point, t_fractal fractal)
{
	unsigned int	i;
	t_complex		z;
	t_complex		c;

	(void)fractal;
	ft_zset(&z, 0.0, 0.0);
	ft_zset(&c, point.x, point.y);
	i = 0;
	while (i++ < CHAR_MAX && isfinite(z.re) && isfinite(z.im))
	{
		ft_zmul(&z, &z, &z); //TODO: Z POW
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
