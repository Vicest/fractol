/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_divergence_steps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:54:21 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/23 15:09:49 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	find_divergence_steps(void *(void *)fractal_funct, void *init_value)
{
	unsigned int n_steps;

	n_steps = 0;
	while (is_finite(init_value) && n_steps <= UINT_MAX)
	{
		init_value = fractal_funct(init_value);
		step++;
	}
	return (n_steps);
}
