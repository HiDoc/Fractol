/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:57:44 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/02 20:45:29 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fractol_calc(t_env *env, t_complex (calc)(t_complex z0),
		t_complex z0, t_complex c)
{
	int			count;
	double		color;
	t_complex	z1;

	color = exp(-c_abs(z0));
	count = 0;
	while (count < MAXITER && (!count || c_abs(z1) < RADSQR))
	{
		z1 = c_add(calc(z0), c);
		z0 = z1;
		color += exp(-c_abs(z0));
		count++;
	}
	return (fractol_color_scale(env, color));
}

t_env		*fractol_iter(t_env *env)
{
	double		x;
	double		y;
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
			env->tab[pos] = env->algo(env, x, y, c);
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
	env->color_modify = 0;
	E_MLX = mlx_init();
	E_WIN = mlx_new_window(E_MLX, WIN_X, WIN_Y, "Fractol");
	E_IMG = mlx_new_image(E_MLX, WIN_X, WIN_Y);
	env->tab = (int *)mlx_get_data_addr(E_IMG, &(E_BPP), &(E_SL), &(E_END));
	return (env);
}
