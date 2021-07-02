/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:18:39 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/01 20:06:07 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(unsigned int value, unsigned int max_value, double zoom)
{
	return (zoom * (value - max_value * 0.5 + 0.5) / (max_value * 0.5));
}
