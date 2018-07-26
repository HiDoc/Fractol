/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:25:56 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/26 19:11:22 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julias(t_env *env, double x, double y, t_complex c)
{
	int			count;
	double		color;
	t_complex	z0;
	t_complex	z1;

	z0.x = RADSQR * (x - WIN_X / 2.0) / WIN_X;
	z0.y = RADSQR * (y - WIN_Y / 2.0) / WIN_Y;
	color = exp(-c_abs(z0));
	count = 0;
	while (count < MAXITER && (!count || c_abs(z1) < RADSQR))
	{
		z1 = c_add(c_sqr(z0), c);
		z0 = z1;
		count++;
		color += exp(-c_abs(z0));
	}
	return (fractol_color_scale(env, color, z1));
}

int		mandel(t_env *env, double x, double y, t_complex c)
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
	while (count < MAXITER && (!count || c_abs(z1) < RADSQR))
	{
		z1 = c_add(c_sqr(z0), c);
		z0 = z1;
		count++;
	}
	return (fractol_color_scale(env, count, z1));
}

int		burnin(t_env *env, double x, double y, t_complex c)
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
		z1.y = 2 * fabs(z0.x * z0.y) + c.y;
		if (c_abs(z1) > RADSQR)
			return (fractol_color_scale(env, count, z1));
		z0 = z1;
		count++;
	}
	return (fractol_color_scale(env, count, z1));
}

int		tripe(t_env *env, double x, double y, t_complex c)
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
	while (count < MAXITER && (!count || c_abs(z1) < RADSQR))
	{
		z1.x = -0.15 * z0.x + 0.28 * z0.y;
		z1.y = 0.26 * z0.x + 0.24 * z0.y + 0.44;
		z0 = z1;
		count++;
	}
	return (fractol_color_scale(env, count, z1));
}

int		newton(t_env *env, double x, double y, t_complex c)
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
		if (c_abs(z1) > RADSQR)
			return (fractol_color_scale(env, count, z1));
		z0 = z1;
		count++;
	}
	return (fractol_color_scale(env, count, z1));
}
