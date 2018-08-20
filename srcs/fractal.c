/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:25:56 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/20 14:10:45 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julias(t_env *env, double x, double y, t_complex c)
{
	t_complex	z0;

	z0.x = RADSQR * (x - WIN_X / 2.0) / WIN_X;
	z0.y = RADSQR * (y - WIN_Y / 2.0) / WIN_Y;
	return (fractol_calc(env, c_sqr, z0, c));	
}

int		mandel(t_env *env, double x, double y, t_complex c)
{
	t_complex	z0;

	c.x = MIN_X + x * PIX_WDT;
	c.y = MIN_Y + y * PIX_HGT;
	if (fabs(c.y) < PIX_HGT / 2)
		c.y = 0;
	z0.x = 0;
	z0.y = 0;
	return (fractol_calc(env, c_sqr, z0, c));	
}

int		burnin(t_env *env, double x, double y, t_complex c)
{
	t_complex	z0;

	c.x = MIN_X + x * PIX_WDT;
	c.y = MIN_Y + y * PIX_HGT;
	if (fabs(c.y) < PIX_HGT / 2)
		c.y = 0;
	z0.x = 0;
	z0.y = 0;
	return (fractol_calc(env, c_sqr_abs, z0, c));	
}

int		tripe(t_env *env, double x, double y, t_complex c)
{
	t_complex	z0;
	t_complex	z1;
	t_complex	z2;
	int			count;
	double		color;

	z0.x = RADSQR * (x - WIN_X / 2.0) / WIN_X;
	z0.y = RADSQR * (y - WIN_Y / 2.0) / WIN_Y;
	color = exp(-c_abs(z0));
	count = 0;
	z2 = z0;
	while (count < MAXITER && (!count || c_abs(z0) < RADSQR))
	{
		z1 = c_add(c_sqr(z0), c_cube(z2));
		z1 = c_add(z1, c);
		z2 = z1;
		z0 = z1;
		color += exp(-c_abs(z0));
		count++;
	}
	return (fractol_color_scale(env, color));
}

int		newton(t_env *env, double x, double y, t_complex c)
{
	t_complex	z0;

	z0.x = MIN_X + x * PIX_WDT;
	z0.y = MIN_Y + y * PIX_HGT;
	return (fractol_calc(env, c_newt, z0, c));
}
