/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:30:44 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 20:39:36 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel(t_image *image, int i_pixel, int j_pixel, unsigned int colour)
{
	const unsigned int	i_offset = i_pixel * (image->bpp / 8);
	const unsigned int	j_offset = j_pixel * image->line_len;

	*(unsigned int *)(image->addr + i_offset + j_offset) = colour;
}
