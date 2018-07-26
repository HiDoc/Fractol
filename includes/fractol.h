/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:22:45 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/26 18:02:21 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "fractol_define.h"
# include "fractol_struct.h"

t_complex	c_add(t_complex a, t_complex b);
t_complex	c_sqr(t_complex c);
double		c_abs(t_complex c);

t_env		*fractol_init();
t_env		*fractol_iter(t_env *env, int (f)(t_env *, double, double, t_complex));

int 		mandel(t_env *env, double x, double y, t_complex c);
int 		julias(t_env *env, double x, double y, t_complex c);
int 		burnin(t_env *env, double x, double y, t_complex c);
int 		newton(t_env *env, double x, double y, t_complex c);
int 		tripe(t_env *env, double x, double y, t_complex c);

int			fractol_color_scale(t_env *env, float count, t_complex c);
int			color_add(int c1);

int			key_hook(int keycode, void *param);
int			ft_strequ(const char *s1, const char *s2);
#endif
