/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 23:21:52 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 23:22:28 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handle(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4 || button == 5)
	{
		fractol->fractal.center.x += scale(x, WIDTH, fractol->fractal.zoom);
		fractol->fractal.center.y += scale(y, HEIGHT, fractol->fractal.zoom);
		mlx_mouse_move(fractol->mlx.window, WIDTH / 2, HEIGHT / 2);
		if (button == 4)
			fractol->fractal.zoom *= 1.25;
		else
			fractol->fractal.zoom *= 0.8;
	}
	refresh(fractol);
	return (0);
}
