/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:28:30 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/02 17:52:38 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	refresh(t_fractol *fractol)
{
	print_fractal(&fractol->mlx.image, fractol->fractal);
	mlx_put_image_to_window(fractol->mlx.server, fractol->mlx.window,
		fractol->mlx.image.ptr, 0, 0);
	mlx_string_put(fractol->mlx.server, fractol->mlx.window,
		0, 10, 0xFFFFFF, "MOVE: Arrowkeys");
	mlx_string_put(fractol->mlx.server, fractol->mlx.window,
		0, 20, 0xFFFFFF, "ZOOM: Mousewheel");
	mlx_string_put(fractol->mlx.server, fractol->mlx.window,
		0, 30, 0xFFFFFF, "Iterations .....");
	mlx_string_put(fractol->mlx.server, fractol->mlx.window,
		0, 40, 0xFFFFFF, "INCREASE/DECREASE ITERATIONS: + / -");
}
