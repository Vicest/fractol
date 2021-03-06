/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:28:30 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 23:36:05 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	refresh(t_fractol *fractol)
{
	print_fractal(&fractol->mlx.image, fractol->fractal);
	mlx_put_image_to_window(fractol->mlx.server, fractol->mlx.window,
		fractol->mlx.image.ptr, 0, 0);
}
