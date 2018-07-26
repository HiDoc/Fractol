/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:59:55 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/26 17:04:34 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tripe(t_env *env, int x, int y, t_complex c)
{
	int			count;
	t_complex	z0;
	t_complex	z1;

	c.x = MIN_X + x * PIX_WDT;
	c.y = MIN_Y + y * PIX_HGT;
	if (fabs(c.y) < PIX_HGT / 2)
		c.y = 0;
	count = 0;
	z0.x = 0;
	z0.y = 0;
	while (count < MAXITER)
	{
		z1.x = z0.x * z0.x - z0.y * z0.y + c.x;
		z1.y = 2 * z0.x * z0.y + c.y;
		if (c_abs(z1) > RADSQR)
			return (fractol_color_scale(env, count, z1));
		z0 = z1;
		count++;
	}
	return (fractol_color_scale(env, count, z1));
}
