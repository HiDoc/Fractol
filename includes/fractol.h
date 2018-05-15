/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:22:45 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/12 18:33:48 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define MAXITER 200
# define WIN_X 800
# define WIN_Y 800
# define MIN_X -1
# define MAX_X 3
# define MIN_Y -2.0
# define MAX_Y 2.0
# define RADIUS 2
# define RADSQR 4
# define PIX_WDT 0.015
# define PIX_HGT 0.015

typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;

t_complex		c_add(t_complex a, t_complex b);	
t_complex		c_sqr(t_complex c);	
double			c_mod(t_complex c);	

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*tab;
	int		bpp;
	int		sl;
	int		endian;
}				t_fract;

t_fract			*fractol_init();
t_fract			*fractol_iter(t_fract *env, int (f)(int, int, t_complex));

int 			mandelbrot(int x, int y, t_complex c);
int 			julia(int x,int y, t_complex c);
int 			other(int x,int y, t_complex c);
int				fractol_color_scale(float count);
#endif
