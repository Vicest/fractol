/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:33:40 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/01 21:17:27 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libftcomplex.h"

void	ft_zpow(t_complex *result, const t_complex *z, double exp)
{
	double	squared_modulus;
	double			argument;

	if (z->re == 0 && z->im == 0)
	{
		ft_zset(result, z->re, z->im);
		return ;
	}
	squared_modulus = z->re * z->re + z->im * z->im;
	argument = atan2(z->im, z->re);
	squared_modulus = pow(squared_modulus, exp * 0.5);
	argument *= exp;
	result->re = squared_modulus * cos(argument);
	result->im = squared_modulus * sin(argument);
}
