/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:42:04 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/21 17:44:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hsv_get_val(t_hsv hsv, double *r, double *g, double *b)
{
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	i = (int)trunc(hsv.h);
	f = hsv.h - i;
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v * (1.0 - (hsv.s * f));
	t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));
	if (i == 0 || i == 1)
		*b = p;
	if (i == 1 || i == 2)
		*g = hsv.v;
	if (i == 2 || i == 3)
		*r = p;
	if (i == 3 || i == 4)
		*b = hsv.v;
	if (i == 4 || i >= 5)
		*g = p;
	if (i == 0 || i >= 5)
		*r = hsv.v;
	if (i == 0)
		*g = t;
	else if (i == 1)
		*r = q;
	else if (i == 2)
		*b = t;
	else if (i == 3)
		*g = q;
	else if (i == 4)
		*r = t;
	else
		*b = q;
}

t_rgb	hsv_to_rgb(t_hsv hsv, t_rgb rgb)
{
	double	r;
	double	g;
	double	b;

	r = 0;
	g = 0;
	b = 0;
	if (hsv.s != 0)
		hsv_get_val(hsv, &r, &g, &b);
	else
	{
		r = hsv.v;
		g = hsv.v;
		b = hsv.v;
	}
	rgb.r = round(r * 255.0);
	rgb.g = round(g * 255.0);
	rgb.b = round(b * 255.0);
	return (rgb);
}

t_hsv	rgb_to_hsv(double r, double g, double b)
{
	double	min;
	double	max;
	double	d;
	t_hsv	hsv;

	max = fmax(r, fmax(g, b));
	min = fmin(r, fmin(g, b));
	d = max - min;
	hsv.v = max / 255.0;
	if (max == min)
		hsv.h = 0;
	else
	{
		if (max == 0)
			hsv.s = 0;
		else
		{
			hsv.s = d / max;
			if (max == r)
				hsv.h = ((g - b) / d);
			if (max == g)
				hsv.h = (b - r) / d + 2;
			if (max == b)
				hsv.h = (r - g) / d + 4;
		}
	}
	return (hsv);
}

int		fractol_color_change(int color, double value)
{
	t_rgb	rgb;
	t_hsv	hsv;
	int		ret;
	double	r;
	double	g;
	double	b;

	(void)value;
	r = ((color >> 16) & 0xFF);
	g = ((color >> 8) & 0xFF);
	b = (color & 0xFF);
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	hsv.h = 0;
	hsv.s = 0;
	hsv.v = 0;
	hsv = rgb_to_hsv(r, g, b);
	hsv.h += value;
	rgb = hsv_to_rgb(hsv, rgb);
	ret = ((rgb.r & 0xFF) << 16) + (((rgb.g & 0xFF)) << 8) + (rgb.b & 0xFF);
	return (ret);
}

int		fractol_color_scale(t_env *env, float count)
{
	t_rgb	rgb;
	t_hsv	hsv;
	int		ret;

	hsv.h = count / (double)MAXITER * 360.0;
	hsv.h += env->color_modify;
	hsv.h =  hsv.h / 60.0;
	hsv.s = 0.80;
	hsv.v = 1.0;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	rgb = hsv_to_rgb(hsv, rgb);
	ret = (rgb.r << 16) + (rgb.g << 8) + (rgb.b);
	return (fractol_color_change(ret, 0.0));
}
