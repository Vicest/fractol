/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:39:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/02 22:41:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"

void	load_multibrot(t_fractal *fractal, int argn, char **argv)
{
	(void)argn;
	(void)argv;
	fractal->zoom = 1.5625;
	fractal->max_iter = 0x1F;
	/*
	if (argn > 0)
	{
		fractal->init.x = f
		if (argn > 2)
	}
	*/
	fractal->function = multibrot;
}

unsigned int	multibrot(t_point point, t_fractal fractal)
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
		ft_zpow(&z, &z, 3);
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
