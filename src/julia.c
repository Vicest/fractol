/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:10:29 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 20:30:36 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"

void	load_julia(t_fractal *fractal, int argn, char **argv)
{
	fractal->custom_param1 = 0.285;
	fractal->custom_param2 = 0.01;
	fractal->max_iter = 0xFF;
	fractal->escape_radius = 4;
	if (argn > 0)
	{
		fractal->custom_param1 = ft_atof(argv[0]);
		if (argn > 1)
			fractal->custom_param2 = ft_atof(argv[1]);
	}
	fractal->function = julia;
}

unsigned int	julia(t_point point, t_fractal fractal)
{
	unsigned char	i;
	t_complex		z;
	t_complex		c;

	ft_zset(&z, point.x, point.y);
	ft_zset(&c, fractal.custom_param1, fractal.custom_param2);
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
