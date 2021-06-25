/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:01:57 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/23 12:13:01 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libftcomplex.h"

inline double	ft_zmod(t_complex *z)
{
	return (sqrt(z->re * z->re + z->im * z->im));
}
