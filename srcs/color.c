/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:42:04 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/23 19:12:13 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fractol_color_bichro(t_env *env, float count)
{
	t_rgb	rgb;
	t_hsv	hsv;
	int		ret;

	hsv.h = env->color_modify / 60.0;
	hsv.s = 1.0;
	hsv.v = count / (double)MAXITER;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	rgb = hsv_to_rgb(hsv, rgb);
	ret = (rgb.r << 16) + (rgb.g << 8) + (rgb.b);
	return (ret);
}

int		fractol_color_scale(t_env *env, float count)
{
	t_rgb	rgb;
	t_hsv	hsv;
	int		ret;

	hsv.h = count / (double)MAXITER * 360.0;
	hsv.h += env->color_modify;
	hsv.h > 360 ? hsv.h -= 360.0 : 0;
	hsv.h = hsv.h / 60.0;
	hsv.s = 0.80;
	hsv.v = 1.0;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	rgb = hsv_to_rgb(hsv, rgb);
	ret = (rgb.r << 16) + (rgb.g << 8) + (rgb.b);
	return (ret);
}
