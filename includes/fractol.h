/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:22:45 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/06 20:07:01 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

# define MAXITER 50

# define WIN_X 800
# define WIN_Y 800

# define MIN_X -2
# define MAX_X 2
# define MIN_Y -2.0
# define MAX_Y 2.0

# define RADIUS 2
# define RADSQR 4
# define PIX_WDT 0.005
# define PIX_HGT 0.005

typedef struct s_env		t_env;
typedef struct s_complex	t_complex;
typedef struct s_move		t_move;

struct						s_complex
{
	double x;
	double y;
};

t_complex					c_add(t_complex a, t_complex b);
t_complex					c_sqr(t_complex c);
double						c_mod(t_complex c);

struct						s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*tab;
	int			bpp;
	int			sl;
	int			endian;
	t_move		*move;
	t_complex	c;
	int			(*algo)(int, int, t_complex);
};

t_env						*fractol_init();
t_env						*fractol_iter(t_env *env, int (f)(int, int, t_complex));

struct						s_move
{
	int			x;
	int			y;
};

int 						mandel(int x, int y, t_complex c);
int 						julias(int x, int y, t_complex c);
int 						burnin(int x, int y, t_complex c);
int 						newton(int x, int y, t_complex c);
int 						tripe(int x, int y, t_complex c);

int							fractol_color_scale(float count);
int							color_add(int c1);

int							key_hook(int keycode, void *param);
int							ft_strequ(const char *s1, const char *s2);
#endif