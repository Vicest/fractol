/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:07:21 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 20:20:19 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

void	ft_zset(t_complex *z, double re, double im)
{
	if (!z)
		return ;
	z->re = re;
	z->im = im;
}
