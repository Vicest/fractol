/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:09:44 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 20:19:20 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

void	ft_zdiv(t_complex *result, t_complex *z1, t_complex *z2)
{
	double	mod_squared;

	if (!result || !z1 || !z2)
		return ;
	ft_zconj(z2, z2);
	ft_zmul(result, z1, z2);
	ft_zconj(z2, z2);
	mod_squared = 0;
	mod_squared = z2->re * z2->re + z2->im * z2->im;
	if (!mod_squared)
		return ;
	result->re /= mod_squared;
	result->im /= mod_squared;
}
