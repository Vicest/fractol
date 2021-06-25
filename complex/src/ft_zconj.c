/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zconj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:32:48 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/23 12:20:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

void	ft_zconj(t_complex *result, t_complex *z)
{
	if (!result || z)
		return ;
	result->re = z->re;
	result->im = -z->im;
}
