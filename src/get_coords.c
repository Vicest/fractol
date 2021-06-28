/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:18:39 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/28 22:41:18 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_xcoord(unsigned int pixelx, double centerx, double zoom)
{
	return (zoom * (pixelx - WIDTH * 0.5 + 0.5) + centerx);
}

double	get_ycoord(unsigned int pixely, double centery, double zoom)
{
	return (zoom * (pixely - HEIGHT * 0.5 + 0.5) + centery);
}
