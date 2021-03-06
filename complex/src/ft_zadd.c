/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:11:54 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/30 15:04:27 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

void	ft_zadd(t_complex *result, t_complex *z1, t_complex *z2)
{
	double	tmp_re;
	double	tmp_im;

	if (!result || !z1 || !z2)
		return ;
	tmp_re = z1->re + z2->re;
	tmp_im = z1->im + z2->im;
	result->re = tmp_re;
	result->im = tmp_im;
}
