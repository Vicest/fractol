/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:02:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/02 22:55:29 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"
#include <math.h>

void	load_burning_ship(t_fractal *fractal, int argn, char **argv)
{
	(void)argn;
	(void)argv;
	fractal->center.x = -0.5;
	fractal->max_iter = 0x7F;
	fractal->function = burning_ship;
}

unsigned int	burning_ship(t_point point, t_fractal fractal)
{
	unsigned int	i;
	t_complex		z;
	t_complex		c;

	(void)fractal;
	ft_zset(&z, 0.0, 0.0);
	ft_zset(&c, point.x, point.y);
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < fractal.max_iter)
	{
		i++;
		ft_zset(&z, fabs(z.re), fabs(z.im));
		ft_zmul(&z, &z, &z);
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
