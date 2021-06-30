/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:03:12 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/30 14:57:13 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	colorize(unsigned int iterations)
{
	unsigned int	color;

	if (iterations >= 144)
		return (0);
	color = 0x0000FF;
	color += (iterations) * 256;
	if (iterations < 128)
		color ^= 0x00FFFFFF;
	return (color);
}
