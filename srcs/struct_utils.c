/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:36:21 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/29 14:36:05 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_ptr_swap(t_env *env, int which)
{
	if (which == 1)
	{
		if (E_ALGL == &fractol_calc)
			E_ALGL = &fractol_calc_sec;
		else
			E_ALGL = &fractol_calc;
	}
	if (which == 2)
	{
		if (E_ALGC == &fractol_color_scale)
			E_ALGC = &fractol_color_bichro;
		else
			E_ALGC = &fractol_color_scale;
	}
	if (which == 3)
	{
		E_ALGL = &fractol_calc_tri;
		E_ALGC = &fractol_color_palet;
	}
	return (1);
}

static void	set_rgb(double *c, double v, int boolean)
{
	if (boolean)
		*c = v;
}

t_rgb		hsv_to_rgb(t_hsv hsv, t_rgb rgb)
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

t_hsv		rgb_to_hsv(double r, double g, double b)
{
	double	min;
	double	max;
	double	d;
	t_hsv	hsv;

	max = fmax(r, fmax(g, b));
	min = fmin(r, fmin(g, b));
	d = max - min;
	hsv.v = max / 255.0;
	hsv.h = 0;
	hsv.s = max != 0 ? d / max : 0;
	if (max != min)
	{
		if (max == r)
			hsv.h = ((g - b) / d);
		if (max == g)
			hsv.h = (b - r) / d + 2.0;
		if (max == b)
			hsv.h = (r - g) / d + 4.0;
	}
	hsv.h < 0 ? hsv.h = hsv.h + 1.0 : 0;
	return (hsv);
}

void		hsv_get_val(t_hsv hsv, double *r, double *g, double *b)
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
	set_rgb(b, p, (i == 0 || i == 1));
	set_rgb(g, hsv.v, (i == 1 || i == 2));
	set_rgb(r, p, (i == 2 || i == 3));
	set_rgb(b, hsv.v, (i == 3 || i == 4));
	set_rgb(g, p, (i == 4 || i == 5));
	set_rgb(r, hsv.v, (i == 0 || i >= 5));
	set_rgb(g, t, i == 0);
	set_rgb(r, q, i == 1);
	set_rgb(b, t, i == 2);
	set_rgb(g, q, i == 3);
	set_rgb(r, t, i == 4);
	set_rgb(b, q, i >= 5);
}
