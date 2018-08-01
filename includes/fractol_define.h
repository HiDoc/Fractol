/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:57:46 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/01 15:24:35 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_DEFINE_H
#define FRACTOL_DEFINE_H
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

# define MAXITER 30

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

# define E_ALG env->algo
# define E_BPP env->bpp
# define E_END env->endian
# define E_IMG env->img
# define E_MLX env->mlx
# define E_MOV env->move
# define E_MOVX env->move->x
# define E_MOVY env->move->y
# define E_SL env->sl
# define E_WIN env->win
#endif
