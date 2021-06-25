/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:47:42 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/23 14:14:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_help()
{
	printf("Invalid usage: fractol [mandelbrot [start|julia] [params]\n");
}

int	main(int argc, char **argv)
{
	if (argc == 1 || !ft_strcmp("mandlebrot", argv[1]) || !ft_strcmp("julia", argv[1]))
	{
		print_help();
		exit(0);
	}
	load_visual();


}
