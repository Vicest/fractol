/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:47:42 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/27 18:39:08 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

static void	print_help()
{
	printf("Invalid usage: fractol [mandelbrot [start|julia] [params]\n");
}

int	quit()
{
	exit(0);
}

static void	initialize_mlx(t_mlx *mlx)
{
	mlx->server = mlx_init();
	if (!mlx->server)
		exit(1);
	mlx->window = mlx_new_window(mlx->server, WIDTH, HEIGHT, "fract-ol");
	if (!mlx->window)
		exit(1);
	mlx->image.ptr = mlx_new_image(mlx->server, WIDTH, HEIGHT);
	if (!mlx->image.ptr)
		exit(1);
	mlx->image.addr = mlx_get_data_addr(mlx->image.ptr, &mlx->image.bpp,
		&mlx->image.line_len, &mlx->image.endian);
	if (!mlx->image.addr)
		exit(1);
}

int	keyboard_handle(int key, t_fractol *fractol)
{
	printf("%d\n", key);
	if (53 == key)
		quit();
	else if (126 == key)
		fractol->fractal.zoom= 0.5;
	else if (125 == key)
		fractol->fractal.zoom *= 2;
	print_fractal(&(fractol->mlx.image), fractol->fractal);
	mlx_put_image_to_window(fractol->mlx.server, fractol->mlx.window,
		fractol->mlx.image.ptr, 0, 0);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4 || button == 5)
	{
		fractol->fractal.center.x = x;
		fractol->fractal.center.y = y;
		if (button == 4)
			fractol->fractal.zoom *= 0.5;
		else
			fractol->fractal.zoom *= 2;
	}
	print_fractal(&(fractol->mlx.image), fractol->fractal);
	mlx_put_image_to_window(fractol->mlx.server, fractol->mlx.window,
		fractol->mlx.image.ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!validate_args(argc, argv))
	{
		print_help();
		exit(0);
	}
	initialize_fractal(&fractol.fractal, argv[1]);
	initialize_mlx(&fractol.mlx);
	print_fractal(&fractol.mlx.image, fractol.fractal);
	mlx_put_image_to_window(fractol.mlx.server, fractol.mlx.window,
		fractol.mlx.image.ptr, 0, 0);
	mlx_key_hook(fractol.mlx.window, keyboard_handle, &fractol);
	mlx_mouse_hook(fractol.mlx.window, mouse_handle, &fractol);
	//mlx_hook(fractol.mlx.window, 5, 0L, mouse_handle, &fractol);
	mlx_hook(fractol.mlx.window, 17, 1L<<17, quit, &fractol);
	mlx_loop(fractol.mlx.server);
 }
