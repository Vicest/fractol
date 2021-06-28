/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:07:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/28 20:51:18 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"
#include <math.h>
#include <limits.h>

unsigned char	mandelbrot(t_point point)
{
	unsigned short	i;
	t_complex		z;
	t_complex		c;

	ft_zset(&z, 0.0, 0.0);
	ft_zset(&c, point.x, point.y);
	i = 0;
	while (i++ < SHRT_MAX / 64 && !isinf(z.re) && !isinf(z.im))
	{
		ft_zmul(&z, &z, &z); //TODO: Z POW
		ft_zadd(&z, &z, &c);
	}
	if (i == SHRT_MAX / 64)
		return (0);
	return (i);
}
