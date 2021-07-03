/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:10:29 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/02 22:30:23 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"

void	load_julia(t_fractal *fractal, int argn, char **argv)
{
	(void)argn;
	(void)argv;
	fractal->init.x = 0.1;
	fractal->init.x = 0.285;
	fractal->max_iter = 0x7F;
	/*
	if (argn > 1)
	{
		fractal->init.x = 
		if (argn > 2)
	}
	*/
	fractal->function = julia;
}

unsigned int	julia(t_point point, t_fractal fractal)
{
	unsigned char	i;
	t_complex		z;
	t_complex		c;

	ft_zset(&z, point.x, point.y);
	ft_zset(&c, fractal.init.x, fractal.init.y);
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < fractal.max_iter)
	{
		i++;
		ft_zmul(&z, &z, &z);
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
