/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:47:42 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 23:30:35 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static void	print_help(void)
{
	ft_putstr_fd("Invalid usage: fractol [<fractal_name>] [params]\n"
		"mandelbrot: no params\n"
		"burning_ship: no params\n"
		"julia: real imaginary\n"
		"mandelbar: exponent\n"
		"multibrot: exponent\n", 1);
}

int	quit(void)
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

static void	initialize_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx.window, keyboard_handle, fractol);
	mlx_mouse_hook(fractol->mlx.window, mouse_handle, fractol);
	mlx_hook(fractol->mlx.window, 17, 1L << 17, quit, fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!validate_args(argc, argv))
	{
		print_help();
		exit(0);
	}
	initialize_fractal(&fractol.fractal, argc - 1, &(argv[1]));
	initialize_mlx(&fractol.mlx);
	initialize_hooks(&fractol);
	refresh(&fractol);
	mlx_loop(fractol.mlx.server);
}
