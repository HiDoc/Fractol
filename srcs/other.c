/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:25:56 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/12 18:32:02 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		other(int x, int y, t_complex c)
{
	int			count;
	t_complex	z0;
	t_complex	z1;

	c.x = MIN_X + x * PIX_WDT;
	c.y = MIN_Y + y * PIX_HGT;
	if (fabs(c.y) < PIX_HGT / 2)
		c.y = 0;
	z0.x = 0;
	z0.y = 0;
	count = 0;
	while (count < MAXITER)
	{
		z1.y = z0.y * z0.y - z0.x * z0.x * z0.x + c.x *c.x;
		z1.x = 2 * z0.y * z0.x - c.y;
		if (c_mod(z1) > RADIUS)
			return (fractol_color_scale(count % 100));
		z0 = z1;
		count++;
	}
	return fractol_color_scale(0);
}
