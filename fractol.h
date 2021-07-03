/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:15:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/03 23:33:33 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 680
# endif
# define KEY_ESC 53
# define KEY_C 8
# define KEY_PLUS 69
# define KEY_MINUS 78
# define ARROWKEY_UP 126
# define ARROWKEY_DOWN 125
# define ARROWKEY_LEFT 124
# define ARROWKEY_RIGHT 123

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

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
	double			zoom;
	double			escape_radius;
	double			custom_param1;
	double			custom_param2;
	t_point			center;
	unsigned	int	(*function)(t_point, struct s_fractal);
	unsigned int	max_iter;
	char			color_shift;
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
void			initialize_fractal(t_fractal *fractal, int argn,
					char **fractal_argv);
double			scale(unsigned int value, unsigned int max_value, double zoom);
void			get_point(t_point *point, t_pixel pixel, t_point center,
					double zoom);
void			set_pixel(t_image*image, int i_pixel, int j_pixel,
					unsigned int colour);
int				keyboard_handle(int key, t_fractol *fractol);
int				mouse_handle(int button, int x, int y, t_fractol *fractol);
void			print_fractal(t_image *image, t_fractal fractal);
unsigned int	colorize(unsigned int iterations, unsigned int max_iter,
					char shift);
void			refresh(t_fractol *fractol);
int				quit(void);

//Fractal functions//

void			load_mandelbrot(t_fractal *fractal, int argn, char **argv);
unsigned int	mandelbrot(t_point point, t_fractal fractal);

void			load_julia(t_fractal *fractal, int argn, char **argv);
unsigned int	julia(t_point point, t_fractal fractal);

void			load_multibrot(t_fractal *fractal, int argn, char **argv);
unsigned int	multibrot(t_point point, t_fractal fractal);

void			load_mandelbar(t_fractal *fractal, int argn, char **argv);
unsigned int	mandelbar(t_point point, t_fractal fractal);

void			load_burning_ship(t_fractal *fractal, int argn, char **argv);
unsigned int	burning_ship(t_point point, t_fractal fractal);
#endif
