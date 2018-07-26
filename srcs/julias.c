/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:25:56 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/26 17:57:54 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julias(t_env *env, int x, int y, t_complex c)
{
	int			count;
	double		color;
	t_complex	z0;
	t_complex	z1;

	z0.x = RADSQR * (x - WIN_X / 2.0) / WIN_X;
	z0.y = RADSQR * (y - WIN_Y / 2.0) / WIN_Y;
	color = exp(-c_abs(z0));
	count = 0;
	while (count < MAXITER && (!count || c_abs(z1) < RADIUS))
	{
		z1 = c_add(c_sqr(z0), c);
		z0 = z1;
		count++;
		color += exp(-c_abs(z0));
	}
	return (fractol_color_scale(env, color, z1));
}
