/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:08:22 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/02 17:02:55 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

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
		fractol->fractal.max_iter -= 10;
	else if (key == KEY_PLUS)
		fractol->fractal.max_iter += 10;
	else if (key == KEY_ESC)
		quit();
	else
	{
		printf("%d\n", key);
		return (0);
	}
	refresh(fractol);
	return (0);
}

