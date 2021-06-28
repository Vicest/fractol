/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:15:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/28 14:32:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef WIDTH
#  define WIDTH 1024
# endif
# ifndef HEIGHT
#  define HEIGHT 738
# endif

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_pixel
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	colour;
}				t_pixel;

typedef struct s_fractal
{
	unsigned char	(*function)(t_point);
	t_point			center;
	double			zoom;
}				t_fractal;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_mlx
{
	void	*server;
	void	*window;
	t_image	image;
}				t_mlx;

typedef struct s_fractol
{
	t_mlx		mlx;
	t_fractal	fractal;
}				t_fractol;

int				validate_args(int argc, char **argv);
void			initialize_fractal(t_fractal *fractal, char *fractal_arg);
double			get_xcoord(unsigned int pixelx, double center, double zoom);
double			get_ycoord(unsigned int pixely, double center, double zoom);
void			get_point(t_point *point, t_pixel pixel, t_point center,
					double zoom);
void			set_pixel(t_image*image, int i_pixel, int j_pixel,
					unsigned int colour);
void			print_fractal(t_image *image, t_fractal fractal);
unsigned char	mandelbrot(t_point point);
unsigned char	julia(t_point point);
#endif
