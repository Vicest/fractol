/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zsub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:16:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/23 12:13:30 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

void	ft_zsub(t_complex *result, t_complex *z1, t_complex *z2)
{
	if (!result || !z1 || !z2)
		return ;
	result->re = z1->re - z2->re;
	result->im = z1->im - z2->im;
}
