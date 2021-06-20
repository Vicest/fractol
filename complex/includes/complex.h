/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:11:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/20 21:43:58 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

void	ft_zset(t_complex *restrict z, double re, double im);
void	ft_zadd(t_complex *restrict result, t_complex *restrict z1,
			t_complex *restrict z2);
void	ft_zsub(t_complex *restrict result, t_complex *restrict z1,
			t_complex *restrict z2);
void	ft_mult(t_complex *restrict result, t_complex *restrict z1,
			t_complex *restrict z2);
void	ft_div(t_complex *restrict result, t_complex *restrict z1,
			t_complex *restrict z2);
void	ft_npow(t_complex *restrict result, t_complex *restrict z,
			unsigned int n);
#endif
