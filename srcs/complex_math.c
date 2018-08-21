/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:11:39 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/21 17:33:52 by fmadura          ###   ########.fr       */
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

t_complex	c_cube(t_complex a)
{
	t_complex	c;
	double		xx;
	double		yy;

	xx = a.x * a.x;
	yy = a.y * a.y;
	c.x = xx * a.x - (3 * a.x * yy);
	c.y = (3 * xx * a.y) - yy * a.y;
	return (c);
}

t_complex	c_sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2.0 * a.x * a.y;
	return (c);
}

double		c_abs(t_complex c)
{
	return (sqrt(c.x * c.x + c.y * c.y));
}
