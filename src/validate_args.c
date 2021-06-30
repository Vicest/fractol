/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 04:47:53 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/29 13:25:10 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	validate_args(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!ft_strcmp("mandelbrot", argv[1]))
		return (1);
	if (!ft_strcmp("julia", argv[1]))
		return (1);
	if (!ft_strcmp("newton", argv[1]))
		return (1);
	return (0);
}
