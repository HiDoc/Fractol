/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:57:44 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/22 17:54:33 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*fractol_iter(t_env *env, int (algo)(int, int, t_complex))
{
	int			x;
	int			y;
	int			pos;
	t_complex	c;

	y = 0;
	pos = 0;
	c = env->c;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			env->tab[pos] = algo(env, x, y, c);
			pos++;
			x++;
		}
		y++;
	}
	return (env);
}

t_env		*fractol_init(void)
{
	t_env		*env;
	t_move		*move;

	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
		exit(0);
	if ((move = (t_move *)malloc(sizeof(t_move))) == NULL)
	{
		free(env);
		exit(0);
	}
	env->c.x = 0;
	env->c.y = 0;
	move->x = 0;
	move->y = 0;
	env->move = move;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "Fractol");
	env->img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	env->tab = (int *)mlx_get_data_addr(env->img,
			&(env->bpp), &(env->sl), &(env->endian));
	return (env);
}
