/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:39:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 20:10:46 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"

void	load_multibrot(t_fractal *fractal, int argn, char **argv)
{
	fractal->zoom = 1.5625;
	fractal->max_iter = 0x1F;
	fractal->custom_param1 = 3;
	if (argn > 0)
		fractal->custom_param1 = ft_atof(argv[0]);
	fractal->function = multibrot;
}

unsigned int	multibrot(t_point point, t_fractal fractal)
{
	unsigned int	i;
	t_complex		z;
	t_complex		c;

	ft_zset(&z, 0.0, 0.0);
	ft_zset(&c, point.x, point.y);
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < fractal.max_iter)
	{
		i++;
		ft_zpow(&z, &z, fractal.custom_param1);
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
