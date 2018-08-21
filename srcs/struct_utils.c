/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:36:21 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/21 17:47:04 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static void	set_rgb(double *c, double v, int boolean)
{
	if (boolean)
		*c = v;
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
	set_rgb(*b, p, (i == 0 || i == 1));
	set_rgb(*g, hsv.v, (i == 1 || i == 2));
	//if (i == 0 || i == 1)
	//	*b = p;
//	if (i == 1 || i == 2)
//		*g = hsv.v;
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
