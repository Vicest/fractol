/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:54:34 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 20:10:41 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"

void	load_mandelbar(t_fractal *fractal, int argn, char **argv)
{
	fractal->max_iter = 0x7F;
	fractal->custom_param1 = 3;
	if (argn > 0)
		fractal->custom_param1 = ft_atof(argv[0]);
	fractal->function = mandelbar;
}

unsigned int	mandelbar(t_point point, t_fractal fractal)
{
	const double	exp = fractal.custom_param1;
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
		z.im = -z.im;
		ft_zpow(&z, &z, exp);
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
