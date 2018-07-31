/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:11:39 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/29 21:22:48 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	c_sqr_abs(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * fabs(a.x * a.y);
	return (c);
}

t_complex	c_cube(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x * a.x - (3 * a.x * a.y * a.y);
	c.y = (3 * a.x * a.x * a.y) - a.y * a.y * a.y;	
	return (c);
}

t_complex	c_sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}


t_complex	c_newt(t_complex a)
{
	t_complex	c;
	double		d;
	double		xx;
	double		yy;

	xx = a.x * a.x;
	yy = a.y * a.y;
	d = 3.0 * ((xx - yy) * (xx - yy) + 4.0 * xx * yy);
	if (d == 0.0)
		d = 0.000001;
	c.x = (2.0 / 3.0) * a.x + (xx - yy) / d;
	c.y = (2.0 / 3.0) * a.y - 2.0 * a.x * a.y / d;
	return (c);
}

double		c_abs(t_complex c)
{
	return (sqrt(c.x * c.x + c.y * c.y));
}
