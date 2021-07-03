/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:54:34 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/02 22:56:08 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libftcomplex.h"

void	load_mandelbar(t_fractal *fractal, int argn, char **argv)
{
	(void)argn;
	(void)argv;
	fractal->center.x = -0.5;
	fractal->max_iter = 0x7F;
	fractal->function = mandelbar;
}

unsigned int	mandelbar(t_point point, t_fractal fractal)
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
		ft_zconj(&z, &z);
		ft_zmul(&z, &z, &z);
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
