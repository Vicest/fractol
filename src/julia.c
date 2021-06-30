/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:10:29 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/30 12:50:43 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include "libftcomplex.h"
#include <math.h>
#include <limits.h>

unsigned char	julia(t_point point, t_fractal fractal)
{
	unsigned char	i;
	t_complex		z;
	t_complex		c;

	ft_zset(&z, point.x, point.y);
	ft_zset(&c, fractal.init.x, fractal.init.y);
	i = 0;
	while (i++ < CHAR_MAX && !isinf(z.re) && !isinf(z.im))
	{
		ft_zmul(&z, &z, &z); //TODO: Z POW
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
