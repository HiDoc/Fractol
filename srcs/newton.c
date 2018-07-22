/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:25:54 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/22 17:53:01 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		newton(t_env *env, int x, int y, t_complex c)
{
	int			count;
	t_complex	z0;
	t_complex	z1;
	t_complex	d;

	(void)c;
	d.x = MIN_X + (x) * PIX_WDT;
	d.y = MIN_Y + (y) * PIX_HGT;
	if (fabs(d.y) < PIX_HGT / 2)
		d.y = 0;
	count = 0;
	z0.x = 0;
	z0.y = 0;
	while (count < MAXITER)
	{
		z1.x = z0.x * z0.x * z0.x - (3 * z0.x * z0.y * z0.y) - d.x; 	
		z1.y = (3 * z0.x * z0.x * z0.y) - z0.y * z0.y * z0.y - d.y;
		if (c_mod(z1) > RADSQR)
			return (fractol_color_scale(count));
		z0 = z1;
		count++;
	}
	return (fractol_color_scale(count));
}
