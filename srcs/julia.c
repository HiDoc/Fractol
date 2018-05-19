/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:25:56 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/19 17:39:10 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(int x, int y, t_complex c)
{
	int			count;
	t_complex	z0;
	t_complex	z1;

	c.x = 0.285;
	c.y = 0.01;
	z0.x = RADSQR * (x - WIN_X / 2.0) / WIN_X;
	z0.y = RADSQR * (y - WIN_Y / 2.0) / WIN_Y;
	count = 0;
	while (count < MAXITER)
	{
		z1.x = z0.x * z0.x - z0.y * z0.y + c.x;
		z1.y = 2 * z0.x * z0.y + c.y;
		if (c_mod(z1) > RADIUS)
			return (fractol_color_scale(count % 100));
		z0 = z1;
		count++;
	}
	return (fractol_color_scale(0));
}
