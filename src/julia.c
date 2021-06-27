/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:10:29 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/27 12:12:44 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include "libftcomplex.h"
#include <math.h>
#include <limits.h>

unsigned char	julia(t_point point)
{
	unsigned char	i;
	t_complex		z;
	t_complex		c;

	ft_zset(&z, 0.125, -0.8);
	ft_zset(&c, point.x, point.y);
	i = 0;
	while (i++ < CHAR_MAX && !isinf(z.re) && !isinf(z.im))
	{
		ft_zmul(&z, &z, &z); //TODO: Z POW
		ft_zadd(&z, &z, &c);
	}
	return (i);
}
