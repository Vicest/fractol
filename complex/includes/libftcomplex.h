/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftcomplex.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:11:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/01 21:12:15 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTCOMPLEX_H
# define LIBFTCOMPLEX_H

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

inline double	ft_zmod(t_complex *z);

void	ft_zset(t_complex *z, double re, double im);
void	ft_zconj(t_complex *result, t_complex *z);
void	ft_zadd(t_complex *result, t_complex *z1, t_complex *z2);
void	ft_zsub(t_complex *result, t_complex *z1, t_complex *z2);
void	ft_zmul(t_complex *result, t_complex *z1, t_complex *z2);
void	ft_zdiv(t_complex *result, t_complex *z1, t_complex *z2);
void	ft_zpow(t_complex *result, const t_complex *z, double n);
#endif
