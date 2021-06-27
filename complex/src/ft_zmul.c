/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:17:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/27 11:04:03 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

void	ft_zmul(t_complex *result, t_complex *z1, t_complex *z2)
{
	double	tmp_re;
	double	tmp_im;

	if (!result || !z1 || !z2)
		return ;
	tmp_re = z1->re * z2->re - z1->im * z2->im;
	tmp_im = z1->re * z2->im + z1->im * z2->re;
	result->re = tmp_re;
	result->im = tmp_im;
}
