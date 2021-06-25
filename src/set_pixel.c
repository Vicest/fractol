/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:30:44 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/23 14:41:39 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	set_pixel(void *image, int i_pixel, int j_pixel, unsigned int colour)
{
	const unsigned int i_offset = i_pixel * image->bpp / 8;
	const unsigned int j_offset = j_pixel * image->line_len;
	const unsigned int *base_address = (unsigned int *)image->addr;

	base_address[i_offset][j_offset] = colour;
}
