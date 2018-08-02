/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:11:46 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/02 20:08:00 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct s_env		t_env;
typedef struct s_complex	t_complex;
typedef struct s_move		t_move;
typedef struct s_rgb		t_rgb;
typedef struct s_hsv		t_hsv;

struct						s_complex
{
	double x;
	double y;
};

struct						s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*tab;
	int			bpp;
	int			sl;
	int			endian;
	double		color_modify;
	t_move		*move;
	t_complex	c;
	int			(*algo)(t_env *env, double, double, t_complex);
};

struct						s_move
{
	int			x;
	int			y;
};

struct 						s_rgb
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
