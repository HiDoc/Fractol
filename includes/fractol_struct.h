/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:11:46 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/23 19:49:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct s_env		t_env;
typedef struct s_thr		t_thread;
typedef struct s_complex	t_complex;
typedef struct s_move		t_move;
typedef struct s_win		t_win;
typedef struct s_rgb		t_rgb;
typedef struct s_hsv		t_hsv;

struct						s_complex
{
	double x;
	double y;
};

struct						s_win
{
	double		x_start;
	double		y_start;
	double		x_end;
	double		y_end;
	double		pad;
	double		zoom;
};

struct						s_thr
{
	int			nbr;
	t_env		*env;
	pthread_t	thread;
};

struct						s_env
{
	long		flag;
	void		*mlx;
	void		*win;
	void		*img;
	int			*tab;
	int			bpp;
	int			maxiter;
	int			sl;
	int			endian;
	double		color_modify;
	t_move		*move;
	t_win		*wind;
	int			tnbr;
	t_thread	t1;
	t_thread	t2;
	t_thread	t3;
	t_thread	t4;
	t_complex	c;
	int			(*algo)(t_env *env, double, double, t_complex);
	int			(*algocalc)(t_env *env, t_complex (calc)(t_complex), t_complex, t_complex);
	int			(*algocolor)(t_env *env, float);
};

struct						s_move
{
	int			x;
	int			y;
};

struct						s_rgb
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct						s_hsv
{
	double h;
	double s;
	double v;
};

#endif
