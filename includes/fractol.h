/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:15:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/25 19:35:15 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef WIDTH
#  define WIDTH 680
# endif
# ifndef HEIGHT
#  define HEIGHT 400
# endif

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_pixel
{
	unsigned int pixel_x;
	unsigned int pixel_y;
	unsigned int pixel_colour;
}				t_pixel;

typedef struct s_mlx
{
	void	*server;
	void	*window;
	void	*image;
}				t_mlx;

void	set_pixel(void *image, int i_pixel, int j_pixel, unsigned int colour);
#endif
