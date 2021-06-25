/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:17:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/23 12:14:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

void	ft_zmul(t_complex *result, t_complex *z1, t_complex *z2)
{
	if (!result || !z1 || !z2)
		return ;
	result->re = z1->re * z2->re - z1->im * z2->im;
	result->im = z1->re * z2->im + z1->im * z2->re;
}
