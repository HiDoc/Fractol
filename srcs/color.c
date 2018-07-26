/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:42:04 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/26 17:57:37 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hsv_get_val(t_hsv hsv, double *r, double *g, double *b)
{
	int i;
	double f;
	double p;
	double q;
	double t;

	if (hsv.h == 360)
		hsv.h = 0;
	else
		hsv.h = hsv.h / 60;
	i = (int)trunc(hsv.h);
	f = hsv.h - i;
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v * (1.0 - (hsv.s * f));
	t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));

	if (i == 0)
	{
		*r = hsv.v;
		*g = t;
		*b = p;
	}
	else if (i == 1)
	{
		*r = q;
		*g = hsv.v;
		*b = p;
	}
	else if (i == 2)
	{
		*r = p;
		*g = hsv.v;
		*b = t;
	}
	else if (i == 3)
	{
		*r = p;
		*g = q;
		*b = hsv.v;
	}
	else if (i == 4)
	{
		*r = t;
		*g = p;
		*b = hsv.v;
	}
	else
	{
		*r = hsv.v;
		*g = p;
		*b = q;
	}
}

t_rgb	hsv_to_rgb(t_hsv hsv, t_rgb rgb)
{
	double r;
	double g;
	double b;

	r = 0;
	g = 0;
	b = 0;

	if (hsv.s == 0)
	{
		r = hsv.v;
		g = hsv.v;
		b = hsv.v;
	}
	else
		hsv_get_val(hsv, &r, &g, &b);

	rgb.r = r * 255;
	rgb.g = g * 255;
	rgb.b = b * 255;

	return (rgb);
}

int			fractol_color_scale(t_env *env, float count, t_complex z)
{
	t_rgb	rgb;
	t_hsv	hsv;
	int		ret;

	(void)env;
	(void)z;
	hsv.h = count / MAXITER * 360;
	hsv.s = 0.8;
	hsv.v = 1.0; 
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	rgb = hsv_to_rgb(hsv, rgb);
	ret = (rgb.r << 16) + (rgb.g << 8) + (rgb.b);
	return (ret);
}
