/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:08:22 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 23:35:37 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_arrowkey(int key)
{
	return (((key + 1) & 0x7C) == 0x7C);
}

static void	handle_arrow(int key, t_fractal *fractal)
{
	const double	zoom = fractal->zoom;

	if (key == ARROWKEY_UP)
		fractal->center.y += scale(HEIGHT * 0.2, HEIGHT, zoom);
	else if (key == ARROWKEY_DOWN)
		fractal->center.y -= scale(HEIGHT * 0.2, HEIGHT, zoom);
	else if (key == ARROWKEY_LEFT)
		fractal->center.x -= scale(WIDTH * 0.2, WIDTH, zoom);
	else if (key == ARROWKEY_RIGHT)
		fractal->center.x += scale(WIDTH * 0.2, WIDTH, zoom);
}

int	keyboard_handle(int key, t_fractol *fractol)
{
	if (is_arrowkey(key))
		handle_arrow(key, &(fractol->fractal));
	else if (key == KEY_MINUS)
		fractol->fractal.max_iter = ft_max(fractol->fractal.max_iter - 8, 8);
	else if (key == KEY_PLUS)
		fractol->fractal.max_iter = ft_min(fractol->fractal.max_iter + 8, 1024);
	else if (key == KEY_C)
		fractol->fractal.color_shift = (fractol->fractal.color_shift + 1) % 3;
	else if (key == KEY_ESC)
		quit();
	else
		return (0);
	refresh(fractol);
	return (0);
}
