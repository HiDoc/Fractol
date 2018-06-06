/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:42:04 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/06 18:57:04 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color_mixer(int c1, int c2, float mix)
{
	float	r;
	float	g;
	float	b;

	r = ((c1 & 0xFF0000) * (1 - mix) + (c2 & 0xFF0000) * (mix));
	g = ((c1 & 0xFF00) * (1 - mix) + (c2 & 0xFF00) * (mix));
	b = ((c1 & 0xFF) * (1 - mix) + (c2 & 0xFF) * (mix));
	r = ((int)r) & 0xff0000;
	g = ((int)g) & 0xff00;
	b = ((int)b) & 0xff;
	return ((int)(r + g + b));
}

int			color_add(int c1)
{
	return (color_mixer(c1, c1 + c1, 0.5));
}
int			fractol_color_scale(float count)
{
	int		rgb;
	float	mix;

	mix = count / MAXITER * 100;
	rgb = color_mixer(0xFF0000, 0xFF1236, mix);
	return (rgb);
}
