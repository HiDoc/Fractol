/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:25:56 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/22 17:51:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julias(t_env *env, int x, int y, t_complex c)
{
	int			count;
	t_complex	z0;
	t_complex	z1;

	z0.x = RADSQR * (x - WIN_X / 2.0) / WIN_X;
	z0.y = RADSQR * (y - WIN_Y / 2.0) / WIN_Y;
	count = 0;
	while (count < MAXITER)
	{
		z1 = c_add(c_sqr(z0), c);
		if (c_mod(z1) > RADIUS)
			return (fractol_color_scale(count));
		z0 = z1;
		count++;
	}
	return (fractol_color_scale(count));
}
