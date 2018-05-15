/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:57:44 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/11 14:26:22 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract		*fractol_iter(t_fract *env, int (algo)(int, int, t_complex))
{
	int			x;
	int			y;
	int			pos;
	t_complex	c;

	y = 0;
	pos = 0;
	c.x = 0;
	c.y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			env->tab[pos] = algo(x, y, c);
			pos++;
			x++;
		}
		y++;
	}
	return (env);
}

t_fract		*fractol_init()
{
	t_fract *env;

	if ((env = (t_fract *)malloc(sizeof(t_fract))) == NULL)
		exit(0);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "Fractol");
	env->img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	env->tab = (int *)mlx_get_data_addr(env->img,
			&(env->bpp), &(env->sl), &(env->endian));
	return (env);
}
