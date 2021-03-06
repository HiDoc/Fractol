/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:57:46 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/28 18:13:03 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_DEFINE_H
# define FRACTOL_DEFINE_H
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

# define MAXITER env->maxiter

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

# define E_ALG	env->algo
# define E_ALGC	env->algocolor
# define E_ALGL	env->algocalc
# define E_BPP	env->bpp
# define E_END	env->endian
# define E_IMG	env->img
# define E_MLX	env->mlx
# define E_MOV	env->move
# define E_MOVX	env->move->x
# define E_MOVY	env->move->y
# define E_SL	env->sl
# define E_WIN	env->win

# define E_ZOOM		env->wind->zoom
# define E_PAD		env->wind->pad
# define X_START	env->wind->x_start
# define Y_START	env->wind->y_start
# define X_END		env->wind->x_end
# define Y_END		env->wind->y_end

# define T_TH1		env->t1.thread
# define T_TH2		env->t2.thread
# define T_TH3		env->t3.thread
# define T_TH4		env->t4.thread
#endif
