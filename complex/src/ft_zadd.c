/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:11:54 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/23 12:07:59 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

void	ft_zadd(t_complex *result, t_complex *z1, t_complex *z2)
{
	if (!result || !z1 || !z2)
		return ;
	result->re = z1->re + z2->re;
	result->im = z1->im + z2->im;
}
